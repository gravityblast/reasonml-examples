external window : Dom.window = "window" [@@bs.val];

external dom : Dom.document = "document" [@@bs.val];

external getElementById : Dom.document => string => Dom.element = "getElementById" [@@bs.send];

external _requestAnimationFrame : Dom.window => (unit => unit) => unit =
  "requestAnimationFrame" [@@bs.send];

let requestAnimationFrame (f: unit => unit) => _requestAnimationFrame window f;
