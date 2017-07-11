type context;

external getContext : Dom.element => string => context = "getContext" [@@bs.send];

external fillRect : context => float => float => float => float => unit = "fillRect" [@@bs.send];

external clearRect : context => float => float => float => float => unit = "clearRect" [@@bs.send];

external strokeRect : context => float => float => float => float => unit =
  "strokeRect" [@@bs.send];

external beginPath : context => unit = "beginPath" [@@bs.send];

external closePath : context => unit = "closePath" [@@bs.send];

external fill : context => unit = "fill" [@@bs.send];

external fillStyle : context => string => unit = "fillStyle" [@@bs.set];

external moveTo : context => float => float => unit = "moveTo" [@@bs.send];

external lineTo : context => float => float => unit = "lineTo" [@@bs.send];

external arc : context => float => float => float => float => float => bool => unit =
  "arc" [@@bs.send];

external stroke : context => unit = "stroke" [@@bs.send];

let clear (ctx: context) (r: Rect.t) :unit =>
  clearRect ctx r.position.x r.position.y r.size.x r.size.y;
