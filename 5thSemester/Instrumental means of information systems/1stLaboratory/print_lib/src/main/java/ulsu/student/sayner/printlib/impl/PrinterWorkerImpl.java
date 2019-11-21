package ulsu.student.sayner.printlib.impl;

import ulsu.student.sayner.printlib.HelloWorldPrinter;
import ulsu.student.sayner.printlib.PrinterWorker;

import java.awt.print.PrinterException;
import java.awt.print.PrinterJob;

public class PrinterWorkerImpl implements PrinterWorker {

    @Override
    public Boolean print() throws PrinterException {
        System.out.print("Печатаю ... ");

        PrinterJob job = PrinterJob.getPrinterJob();
        job.setPrintable(new HelloWorldPrinter());
        boolean doPrint = job.printDialog();
        System.out.println("starting ... ");

        if (doPrint) {
            try {
                job.print();
                System.out.println("printed");
            } catch (PrinterException e) {
                // The job did not successfully complete
                System.out.println("The job did not successfully complete");
            }
        }

        System.out.println("finished");

        return doPrint;
    }
}
