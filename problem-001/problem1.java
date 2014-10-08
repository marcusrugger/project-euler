package java8;

public class problem1 {

  public static int calc_sum(int step) {
    int sum = 0;
    for (int a = step; a < 1000; a += step)
      sum += a;
    return sum;
  }

  public static void main(String[] args) {
    System.out.println(calc_sum(3) + calc_sum(5) - calc_sum(15));
  }

}
