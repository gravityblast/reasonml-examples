let canvas = Document.getElementById Document.dom "canvas";

let ctx = Canvas.getContext canvas "2d";

let model: Model.t = {
  ball: {position: {x: 10., y: 10.}, direction: {x: 0.8, y: 0.5}, radius: 10., speed: 500.},
  canvasSize: 500.
};

let () = Game.start ctx model;
