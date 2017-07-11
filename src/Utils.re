type date;

external now : unit => date = "Date" [@@bs.new];

external getTime : date => int = "getTime" [@@bs.send];

external mathPI : float = "Math.PI" [@@bs.val];

let getDelta (startDate: date) (endDate: date) =>
  float_of_int (getTime endDate - getTime startDate);
