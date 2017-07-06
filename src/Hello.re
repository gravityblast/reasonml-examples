let component = ReasonReact.statelessComponent "Hello";

let make _children => {
  ...component,
  render: fun _self => {
    <h1>{ReasonReact.stringToElement "Hello World"}</h1>
  }
};
