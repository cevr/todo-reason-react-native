open ReactNative;

type todo = {
  goal: string,
  id: string,
  completed: bool,
};

let makeTodo = goal => {
  goal,
  id: Random.int(100)->Belt.Int.toString,
  completed: false,
};

[@react.component]
let make = () => {
  let (goal, setGoal) = React.useState(() => "");
  let (goals, setGoals) = React.useState(() => [||]);

  <View style={Tw.make("p-5 h-full bg-gray-100")}>
    <View style={Tw.make("pt-12 items-center")}>
      <GoalInput
        onChangeText={goal => setGoal(_ => goal)}
        placeholder="Set a goal!"
        value=goal
        onButtonPress={_ =>
          if (goal->Js.String.length > 0) {
            let goals = goals->Belt.Array.concat([|makeTodo(goal)|]);
            setGoals(_ => goals);
            setGoal(_ => "");
          }
        }
      />
    </View>
    <FlatList
      data=goals
      keyExtractor={(item, _) => item.id}
      style={Tw.make("mt-5")}
      renderItem={props => {
        let {item} = props;
        <TouchableHighlight
          underlayColor={Tw.color("blue-100")}
          onPress={_ =>
            setGoals(
              Js.Array.map(goal =>
                goal.id == item.id
                  ? {...goal, completed: !goal.completed} : goal
              ),
            )
          }
          onLongPress={_ =>
            setGoals(Js.Array.filter(goal => goal.id !== item.id))
          }>
          <Goal goal={item.goal} completed={item.completed} />
        </TouchableHighlight>;
      }}
    />
  </View>;
};
