"use strict";

function minOperations(n) {
  const text = ["H"];
  let count = 0;

  // looping to n time
  for (let i = 0; text.length < n; i++) {
    // copy the arr
    const textCopy = text.slice();

    // paste it 2x
    if (text.length + 2 < n) {
      count += 3;
      text.push(...textCopy);
      text.push(...textCopy);
    } else {
      count += 2;
      text.push(...textCopy);
    }
  }

  return text;
}

console.log(minOperations(9));
