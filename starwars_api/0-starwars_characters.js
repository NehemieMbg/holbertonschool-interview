#!/usr/bin/node
const movieId = process.argv[2];
const request = require('request');

const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;
request(url, async (err, response) => {
  if (err) {
    console.error(err);
    return;
  }
  const data = JSON.parse(response.body);
  const charsData = data.characters;
  for (const charId in charsData) {
    await new Promise((resolve, reject) => {
      request(charsData[charId], function (err, response) {
        if (err) {
          console.error(err);
          reject(new Error('Error making request to API'));
          return;
        }
        const charData = JSON.parse(response.body);
        console.log(charData.name);
        resolve();
      });
    });
  }
});
