
public class ActivitySelection {
    public static class MaxAct {
        private int number;
        private int start;
        private int end;

        public MaxAct(int number, int start, int end) {
            this.number = number;
            this.start = start;
            this.end = end;
        }

        public int getNumber() {
            return number;
        }

        public void setNumber(int number) {
            this.number = number;
        }

        public int getStart() {
            return start;
        }

        public void setStart(int start) {
            this.start = start;
        }

        public int getEnd() {
            return end;
        }

        public void setEnd(int end) {
            this.end = end;
        }
    }

    public void MaxActivity(MaxAct array, int n) {
        int current, next;
        current = 0;

        for (next = 1; next < n; next++)
            if (array.getEnd() < array.getStart()) {
                current = next;
                System.out.println(current);
            }
    }

}
