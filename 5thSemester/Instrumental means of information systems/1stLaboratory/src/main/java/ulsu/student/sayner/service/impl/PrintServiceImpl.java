package ulsu.student.sayner.service.impl;

import org.springframework.stereotype.Service;
import ulsu.student.sayner.service.PrintService;

import java.awt.*;
import java.awt.print.Printable;
import java.awt.print.PrinterException;
import java.awt.print.PrinterJob;

@Service
public class PrintServiceImpl implements PrintService {

    /**
     * Отдаёт документ на печать
     *
     * @return
     */
    @Override
    public Boolean print() throws PrinterException {

        System.out.print("Печатаю ... ");

        PrinterJob printerJob = PrinterJob.getPrinterJob(); // Связывает Java-приложение с принтером, установленым по умолчанию
        printerJob.setPrintable((graphics, pageFormat, pageNumber) -> {

            if (pageNumber > 0) {
                return Printable.NO_SUCH_PAGE;
            } else {
                graphics.drawString("Page " + (pageNumber + 1), 150, 150);
            }

            return Printable.PAGE_EXISTS;
        });

        // если пользователь нажал кнопку "печать"
//        if (printerJob.printDialog()) {
//            // печатаем документ
//            return true;
//        }

        printerJob.print();
        System.out.println("Отмена печати");
        return false;
    }
}
