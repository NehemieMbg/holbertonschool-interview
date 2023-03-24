"use strict";

function lockboxes(boxes) {
  const boxesOpened = new Set([0]);
  const keys = [...boxes[0]];

  while (keys.length > 0) {
    const key = keys.pop();

    if (!boxesOpened.has(key) && key < boxes.length) {
      boxesOpened.add(key);
      keys.push(...boxes[key]);
    }
  }

  return boxesOpened.size === boxes.length;
}

console.log(lockboxes([[1], [2], [3], [4], []]));
console.log(
  lockboxes([[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]])
);
console.log(lockboxes([[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]));
