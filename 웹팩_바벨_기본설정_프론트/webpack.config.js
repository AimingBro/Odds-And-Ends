const path = require('path');
const webpack = require('webpack');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const { CleanWebpackPlugin } = require('clean-webpack-plugin');
const MiniCssExtractPlugin = require('mini-css-extract-plugin');

process.env.NODE_ENV = process.env.NODE_ENV || 'development';
console.log('\n$$$ process.env.NODE_ENV =>', process.env.NODE_ENV, '\n');
module.exports = {
  mode: process.env.NODE_ENV,
  entry: {
    index: './src/index.js',
  },
  output: {
    filename: '[name].js',
    path: path.resolve('./public'),
  },
  module: {
    rules: [
      {
        test: /\.css$/,
        use: [
          process.env.NODE_ENV === 'production'
            ? MiniCssExtractPlugin.loader
            : 'style-loader',
          'css-loader',
        ],
      },
      {
        test: /\.(png|jpg|gif)$/,
        loader: 'file-loader',
        options: {
          //publicPath: './public/', // html가 동일한 경로에 빌드됨
          name: '[name].[ext]?[hash]',
        },
      },
      {
        test: /\.(png|jpg|gif)$/,
        use: {
          loader: 'url-loader',
          options: {
            //publicPath: './public/',  // html가 동일한 경로에 빌드됨
            name: '[name].[ext]?[hash]',
            limit: 5000, // 5kb 미만 파일만 data url로 처리
          },
        },
      },
      {
        test: /\.js$/,
        exclude: /node_modules/,
        loader: 'babel-loader', // 바벨 로더를 추가한다
      },
    ],
  },
  plugins: [
    new webpack.BannerPlugin({
      banner: () => `Build date: ${new Date().toLocaleString()}`,
    }),
    new webpack.DefinePlugin({
      API_DOMAIN: JSON.stringify(process.env.API_DOMAIN),
    }),
    new HtmlWebpackPlugin({
      template: './src/index.html',
      hash: true, // 정적 파일을 불러올때 쿼리문자열에 웹팩 해쉬값을 추가(배포 시 브라우저 캐시 사용 문제 해결)
      templateParameters: {
        env: process.env.NODE_ENV === 'development' ? '(개발용)' : '', //ejs 문법의 변수처럼 사용 가능
      },
      minify:
        process.env.NODE_ENV === 'production'
          ? {
              collapseWhitespace: true, // 빈칸 제거
              removeComments: true, // 주석 제거
            }
          : false,
    }),
    new CleanWebpackPlugin(),
  ].concat(
    process.env.NODE_ENV === 'production'
      ? [new MiniCssExtractPlugin({ filename: '[name].css' })]
      : []
  ),
};
