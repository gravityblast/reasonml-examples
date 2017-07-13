type t = {
  position: Vec.t,
  size: Vec.t
};

let left (rect: t) => rect.position.x -. rect.size.x /. 2.;

let right (rect: t) => rect.position.x +. rect.size.x /. 2.;

let top (rect: t) => rect.position.y -. rect.size.y /. 2.;

let bottom (rect: t) => rect.position.y +. rect.size.y /. 2.;
