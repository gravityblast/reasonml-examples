let isCollidingWith (a: Rect.t) (b: Rect.t) :bool => {
  let x1 = max (Rect.left a) (Rect.left b);
  let x2 = min (Rect.right a) (Rect.right b);
  let y1 = max (Rect.top a) (Rect.top b);
  let y2 = min (Rect.bottom a) (Rect.bottom b);
  x1 < x2 && y1 < y2
};
