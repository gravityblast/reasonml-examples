var path = require("path");

module.exports = {
  entry: './lib/js/src/main.js',
  output: {
    path: __dirname + '/public',
    filename: 'bundle.js',
  },
  devServer: {
    contentBase: path.join(__dirname, "public")
  }
};

