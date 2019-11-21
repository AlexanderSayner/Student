package ulsu.student.sayner.controllers;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import ulsu.student.sayner.printlib.PrinterWorker;
import ulsu.student.sayner.printlib.impl.PrinterWorkerImpl;

import java.awt.print.PrinterException;

@RestController
public class PrintController {

    @GetMapping("/print")
    public String print() throws PrinterException {

        PrinterWorker printerWorker = new PrinterWorkerImpl();
        printerWorker.print();
        return "Отправлено на печать";
    }
}
