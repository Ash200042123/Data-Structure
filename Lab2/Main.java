import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class dynamicArray {
    int arr[];
    int capacity;
    int count;

public dynamicArray(int len) {
    arr=new int[len];
    capacity=len;
    count=0;
}

public int Get(int i) {
    if(i<count) return arr[i];
    else return -1;
}

public void Set(int i,int val) {
    arr[i]=val;
}
public void PushBack(int val) {
    if (capacity == count) {
        int copy_arr[] = new int[2 * count];

        for (int i = 0; i < count; i++) {
            copy_arr[i] = arr[i];
        }
        arr = copy_arr;
        capacity*=2;
    }
    arr[count]=val;
    count++;
}
public void Remove(int i) {
    int copy_arr[]=new int[count];

    for(int j=0;j<i;j++) {
        copy_arr[j]=arr[j];
    }
    for(int j=i+1;j<count;j++) {
        copy_arr[j-1]=arr[j];
    }
    arr=copy_arr;
    count--;
}

public int Size() {
        return count;
}

public int Capacity() {
    return capacity;
}
}
public class Main {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scan=new Scanner(System.in);
//        dynamicArray a= new dynamicArray(5);
//        a.PushBack(1);
//        a.PushBack(2);
//        a.PushBack(3);
//        a.PushBack(4);
//        a.PushBack(5);
//
//        a.PushBack((9));
//
//        //System.out.println(a.Get(2));
//        a.Set(2,100);
//        System.out.println(a.Get(2));
//        a.Remove(3);
//        for(int i=0;i<a.Size();i++)
//        System.out.print(a.Get(i)+" ");
//        System.out.println(a.Size());
//        System.out.println(a.Capacity());


        System.out.println("Enter the number:");

        dynamicArray arr=new dynamicArray(1);
        dynamicArray arr2= new dynamicArray(5);
        while(scan.hasNextInt()) {
            arr.PushBack(scan.nextInt());
        }
        double sum=0;
        for(int i=0,j=arr.Size()-1;i<arr.Size();i++,j--) {
            sum= sum+(arr.Get(i)*Math.pow(10,j));
        }
        sum++;
        System.out.println(sum);

        int i = 0, j = arr.Size() - 1;

        while(sum>0) {

                double x = sum / Math.pow(10, j);

                if (x >= 9) {
                    x = x % 9;
                }
                sum %= Math.pow(10, j);
                int y = (int) x;
                arr2.PushBack(y);

                i++;j--;

        }
        if(arr2.Size()<arr.Size()){
            int x=(arr.Size()-arr2.Size())+1;
            while(x>0){
                arr2.PushBack(0);
                x--;
            }
        }
        for(int k=0;k<arr2.Size();k++){
            System.out.print(arr2.Get(k)+" ");
        }
      }
}

