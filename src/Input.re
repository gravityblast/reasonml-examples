type t = {
  up: bool,
  down: bool,
  left: bool,
  right: bool
};

let make () => {up: false, down: false, left: false, right: false};

let keyDown input event =>
  switch (Document.eventKey event) {
  | "ArrowUp" => {...input, up: true}
  | "ArrowDown" => {...input, down: true}
  | "ArrowLeft" => {...input, left: true}
  | "ArrowRight" => {...input, right: true}
  | _ => input
  };

let keyUp input event =>
  switch (Document.eventKey event) {
  | "ArrowUp" => {...input, up: false}
  | "ArrowDown" => {...input, down: false}
  | "ArrowLeft" => {...input, left: false}
  | "ArrowRight" => {...input, right: false}
  | _ => input
  };
