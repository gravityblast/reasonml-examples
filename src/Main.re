let canvas = Document.getElementById Document.dom "canvas";

let ctx = Canvas.getContext canvas "2d";

let model: Model.t = Model.make ();

let () = Game.start ctx model;
