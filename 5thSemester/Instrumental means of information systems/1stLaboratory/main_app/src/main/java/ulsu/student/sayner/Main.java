package ulsu.student.sayner;

import ulsu.student.sayner.printlib.PrinterWorker;
import ulsu.student.sayner.printlib.impl.PrinterWorkerImpl;

public class Main {

    public static void main(String[] args) throws Exception {
        PrinterWorker printerWorker = new PrinterWorkerImpl();
        printerWorker.print();
    }
}
