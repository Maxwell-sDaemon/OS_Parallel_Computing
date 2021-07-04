/*
 *	peseudo-code
 (problem)
 if problem is small enough
 	solve the problem directly
 else
 	subtask1 = fork(new Task(subset of problem)
 	subtask2 = fork(new Task(subset of problem)
 	result1 = join(subtask1)
 	result2 = join(subtask2)
 	return combined results
 *
 * */
import java.util.concurrent.*;
import 	java.util.Scanner;

public class SumTask extends RecursiveTask<Integer>
{
	static final int THRESHOLD = 1000;
	private int begin;
	private int end;
	private int[] array;
	public SumTask(int begin, int end, int[] array) {
		this.begin = begin;
		this.end = end;
		this.array = array;
	}
	protected Integer compute() {
		if (end - begin < THRESHOLD) {
			int sum = 0;
			for (int i = begin; i <= end; i++)
				sum += array[i];
			return sum;
		}
		else {
			int mid = (begin + end) / 2;
			SumTask leftTask = new SumTask(begin, mid, array);
			SumTask rightTask = new SumTask(mid + 1, end, array);
			leftTask. fork ();
			rightTask. fork ();
			return rightTask.join() + leftTask.join();
		}
	}


	
	public static void main(String[] argv) {
	
		ForkJoinPool pool = new ForkJoinPool();

		Scanner sc = new Scanner(System.in);
		final int SIZE = sc.nextInt();

		
		int[] array = new int[SIZE];
		
		for( int i = 0 ; i < array.length ; i++){
			array[i] = i;
			System.out.println("array " + i  + " "+ array[i]);
	
		}
		
		SumTask task = new SumTask(0, SIZE - 1 , array);
		int sum = pool.invoke(task);

		System.out.println("sum:" + sum);
	}
}



