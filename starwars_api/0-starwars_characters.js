#!/usr/bin/node
// api
const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`;
request(url, async function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const characters = JSON.parse(body).characters;
    for (const c in characters) {
      const response = await new Promise((resolve, reject) => {
        request(characters[c], (error, response, body) => {
          if (error) {
            reject(error);
          } else {
            resolve(JSON.parse(body).name);
          }
        });
      });
      console.log(response);
    }
  }
});
