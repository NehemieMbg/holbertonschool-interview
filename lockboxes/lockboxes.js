"use strict";

function lockboxes(boxes) {
  let count = 1;
  let i = 0;
  const boxesOpened = { 0: true };
  const keys = [];

  boxes[0].forEach((key) => {
    keys.push(key);
  });

  while (i < boxes.length) {
    if (keys.includes(i)) {
      if (!boxesOpened[i]) count++;
      boxesOpened[i] = true;

      // Avoid double keys
      boxes[i].forEach((key) => {
        if (!keys.includes(key)) {
          keys.push(key);
          i = 1;
        }
      });
    }

    i++;
  }

  return count === boxes.length;
}

console.log(lockboxes([[1], [2], [3], [4], []]));
console.log(
  lockboxes([[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]])
);
console.log(lockboxes([[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]));
