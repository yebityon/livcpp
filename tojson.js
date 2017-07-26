#!/usr/bin/env node

const fs = require('fs');
const path = require('path');

function traverse(dir, done) {
  let results = [];
  fs.readdir(dir, (err, list) => {
    if (err) return done(err);
    let pending = list.length;
    if (!pending) return done(null, results);
    list.forEach(file => {
      file = path.resolve(dir, file);
      fs.stat(file, (err, stat) => {
        if (stat && stat.isDirectory()) {
          traverse(file, (err, res) => {
            results = results.concat(res);
            if (!--pending) done(null, results);
          });
        } else {
          results.push(file);
          if (!--pending) done(null, results);
        }
      });
    });
  });
}

traverse('./src/', (err, files) => {
  if (err) throw err;
  const obj = {};
  files.forEach(file => {
    const text = fs.readFileSync(file, 'utf8');
    const name = path.relative('./src/', file).split('.')[0];
    obj[name] = {
      prefix: `_${name}`,
      body: text.split('\n')
    };
  });
  console.log(JSON.stringify(obj));
});
