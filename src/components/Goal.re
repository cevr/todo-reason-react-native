open ReactNative;

type styles = {
  container: Style.t,
  text: Style.t,
};

let styles = {
  container: Tw.make("flex justify-start rounded-md px-2 py-2 my-2"),
  text: Tw.make("flex-grow text-gray-700 font-medium px-2"),
};

[@react.component]
let make = (~goal, ~completed) => {
  <View style={styles.container}>
    <Text
      style={Style.array([|
        styles.text,
        Tw.(make("line-through"->Cn.on(completed))),
      |])}>
      goal->React.string
    </Text>
  </View>;
};
