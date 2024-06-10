var readline = require("readline");
var reader = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let width :number, height :number;
let maxDistance :number = 0;
let count :number = 0;

let area :string[] = [];
let startsPoint :number[][] = [];

let neswY :number[] = [-1, 0, 1, 0];
let neswX :number[] = [0, 1, 0, -1];

reader.on('line', getInput).on('close', getDistance);

function getInput(input: string) :void {
    if(count == 0) {
        [height, width] = input.trim().split(' ')
            .filter((element: string) => element != "")
            .map((element :string) => parseInt(element));
    }

    if(count > 0 && count <= height) area.push(input);
    count++;

    if(count > height) {
        findStartPoints();
        reader.close();
    }
}

function findStartPoints() :void {
    for(let i :number = 0; i < height; i++) {
        for(let j :number = 0; j < width; j++) {
            if(area[i][j] != 'L')   continue;

            let cantGoUp :boolean = i == 0 || area[i-1][j] != 'L';
            let cantGoDown :boolean = i == height-1 || area[i+1][j] != 'L';
            let cantGoLeft :boolean = j == 0 || area[i][j-1] != 'L';
            let cantGoright :boolean = j == width-1 || area[i][j+1] != 'L';

            if(!cantGoUp && !cantGoDown)        continue;
            if(!cantGoLeft && !cantGoright)     continue;

            startsPoint.push([i, j]);
        }    
    }

    // console.log(startsPoint);
}

function getDistance() :void {
    for(let i :number = 0; i < startsPoint.length; i++) {
        let y :number = startsPoint[i][0];
        let x :number = startsPoint[i][1];

        dfs([[y, x]], 1);
    }

    console.log(maxDistance);
}

function dfs(path :number[][], distance :number) {
    // console.log(y + ", " + x + ", " + previousDirection + ", " + distance);

    maxDistance = maxDistance < distance ? distance : maxDistance;

    for(let i :number = 0; i < 4; i++) {
        let nextY :number = path[path.length-1][0] + neswY[i];
        let nextX :number = path[path.length-1][1] + neswX[i];

        if(path.indexOf([nextY, nextX]) > -1)    continue;
        if(nextY < 0 || nextY == height)    continue;
        if(nextX < 0 || nextX == width)     continue;
        if(area[nextY][nextX] != 'L')       continue;

        let newPath :number[][] = [...path, [nextY, nextX]];

        dfs(newPath, distance+1);
    }
}