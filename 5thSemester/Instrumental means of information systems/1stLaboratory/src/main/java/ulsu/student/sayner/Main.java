package ulsu.student.sayner;

import javax.print.attribute.standard.JobSheets;
import javax.swing.*;
import java.awt.*;
import java.awt.print.*;
import java.text.MessageFormat;
import java.util.List;

public class Main {

    public static void main(String[] args) throws Exception {

        PrinterJob job = PrinterJob.getPrinterJob();
        PageFormat pf = job.defaultPage();
        PageFormat pf2 = job.pageDialog(pf);
        if (pf2 != pf) {
            job.setPrintable((graphics, pageFormat, pageNumber) -> {
                if (pageNumber > 0) {
                    return Printable.NO_SUCH_PAGE;
                } else {
                    graphics.drawString("Page " + (pageNumber + 1), 150, 150);
                }

                return Printable.PAGE_EXISTS;
            }, pf2);

            if (job.printDialog()) {
//                try {
                    job.print();
//                } catch (PrinterException e) {
//                    System.out.println("Ну нахер");
//                }
            }
        }
    }
}
