let start (ctx: Canvas.context) (model: Model.t) => {
  let lastFrameTime = ref (Utils.now ());
  let m = ref model;
  let rec loop () => {
    let now = Utils.now ();
    let elapsed = Utils.getDelta !lastFrameTime now;
    let dt = elapsed > 50. ? 50. : elapsed;
    m := Game.update dt !m;
    Game.draw ctx !m;
    lastFrameTime := now;
    Document.requestAnimationFrame loop
  };
  loop ()
};

let canvas = Document.getElementById Document.dom "canvas";

let ctx = Canvas.getContext canvas "2d";

let model: Model.t = {
  ball: {position: {x: 10., y: 10.}, direction: {x: 0.8, y: 0.5}, radius: 10., speed: 500.},
  canvasSize: 500.
};

start ctx model;
