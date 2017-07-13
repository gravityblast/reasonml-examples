type event;

external window : Dom.window = "window" [@@bs.val];

external dom : Dom.document = "document" [@@bs.val];

external getElementById : Dom.document => string => Dom.element = "getElementById" [@@bs.send];

external _requestAnimationFrame : Dom.window => (unit => unit) => unit =
  "requestAnimationFrame" [@@bs.send];

external _addEventListener : Dom.document => string => (event => unit) => unit =
  "addEventListener" [@@bs.send];

external eventKey : event => string = "key" [@@bs.get];

let requestAnimationFrame (f: unit => unit) => _requestAnimationFrame window f;

let addEventListener eventName f => _addEventListener dom eventName f;
