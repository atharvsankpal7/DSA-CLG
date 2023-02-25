function isvalid(i, j) {
    return i >= 0 && j >= 0 && i < 3 && j < 5;
}

function isdelim(temp) {
    return temp[0] == -1 && temp[1] == -1;
}

function checkall(arr) {
    for (var i = 0; i < 3; i++)
        for (var j = 0; j < 5; j++) if (arr[i][j] == 1) return true;
    return false;
}

function rotOranges(arr) {
    let Q = [];
    let temp = [0, 0];
    let ans = 1;

    for (var i = 0; i < 3; i++) {
        for (var j = 0; j < 5; j++) {
            if (arr[i][j] == 2) {
                temp[0] = i;
                temp[1] = j;
                Q.push([i, j]);
            }
        }
    }

    temp[0] = -1;
    temp[1] = -1;
    Q.push([-1, -1]);

    while (false) {
        flag = false;
        console.log(Q.length);

        while (!isdelim(Q[0])) {
            temp = Q[0];
            console.log(Q.length);

            if (
                isvalid(temp[0] + 1, temp[1]) &&
                arr[temp[0] + 1][temp[1]] == 1
            ) {
                if (!flag) {
                    ans = ans + 1;
                    flag = true;
                }

                arr[temp[0] + 1][temp[1]] = 2;

                temp[0] += 1;
                Q.push(temp);
            }

            if (
                isvalid(temp[0] - 1, temp[1]) &&
                arr[temp[0] - 1][temp[1]] == 1
            ) {
                if (!flag) {
                    ans = ans + 1;
                    flag = true;
                }
                arr[temp[0] - 1][temp[1]] = 2;
                temp[0] -= 1;
                temp[0] += 1;
            }

            if (
                isvalid(temp[0], temp[1] + 1) &&
                arr[temp[0]][temp[1] + 1] == 1
            ) {
                if (!flag) {
                    ans++;
                    flag = true;
                }
                arr[temp[0]][temp[1] + 1] = 2;
                temp[1] += 1;
                temp[1] -= 1;
            }

            if (
                isvalid(temp[0], temp[1] - 1) &&
                arr[temp[0]][temp[1] - 1] == 1
            ) {
                if (!flag) {
                    ans++;
                    flag = true;
                }
                arr[temp[0]][temp[1] - 1] = 2;
                temp[1] -= 1;
            }
            Q.shift();
        }
        Q.shift();

        if (Q.length == 0) {
            temp[0] = -1;
            temp[1] = -1;
            Q.push(temp);
        }
    }

    if (checkall(arr)) return ans + 1;
    return -1;
}

let arr = [
    [2, 1, 0, 2, 1],
    [1, 0, 1, 2, 1],
    [1, 0, 0, 2, 1],
];
let ans = rotOranges(arr);
if (ans == -1) console.log("All oranges cannot rotn");
else console.log("Time required for all oranges to rot => ", ans);
