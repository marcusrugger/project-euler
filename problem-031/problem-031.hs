target_value = 200
coin_values = [1, 2, 5, 10, 20, 50, 100, 200]


evaluate_path value index =
  if (value > target_value || index == length coin_values)
    then 0
    else if (value == target_value)
      then 1
      else (evaluate_path (value + (coin_values !! index)) index) +
           (evaluate_path value (index+1))
