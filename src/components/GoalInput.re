open ReactNative;

[@react.component]
let make = (~onChangeText=?, ~value=?, ~placeholder=?, ~onButtonPress) =>
  <View style={Tw.make("w-full relative h-12")}>
    <TextInput
      style={Tw.make(
        "bg-white text-gray-600 h-full px-5 pr-10 rounded-full text-sm w-full",
      )}
      ?placeholder
      ?onChangeText
      ?value
      placeholderTextColor={Tw.color("gray-400")}
    />
    <TouchableOpacity
      style={Tw.make("text-6xl absolute right-0 mt-3 mr-4 h-full w-5")}
      onPress=onButtonPress>
      <Text> "+"->React.string </Text>
    </TouchableOpacity>
  </View>;
