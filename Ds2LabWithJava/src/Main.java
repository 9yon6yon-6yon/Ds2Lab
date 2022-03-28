import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ActivitySelection.MaxAct job = null;
        for (int i = 0; i < n; i++) {
            job = new ActivitySelection.MaxAct(sc.nextInt(), sc.nextInt(), sc.nextInt());
        }
        ArrayList<ActivitySelection.MaxAct> arrayList = new ArrayList<>();
        arrayList.add(job);

        arrayList.sort(new Comparator<ActivitySelection.MaxAct>() {
            @Override
            public int compare(ActivitySelection.MaxAct maxAct, ActivitySelection.MaxAct t1) {
                return Integer.compare(maxAct.getEnd(), t1.getEnd());
            }
        });
         ActivitySelection activitySelection = new ActivitySelection();
         activitySelection.MaxActivity(job,n);
    }
}
