package ulsu.student.sayner.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import ulsu.student.sayner.service.PrintService;

import java.awt.print.PrinterException;

@RestController("/print")
public class PrintController {

    private final PrintService printService;

    public PrintController(PrintService printService) {
        this.printService = printService;
    }

    @GetMapping
    public String print() throws PrinterException {

        printService.print();
        return "Отправлено на печать";
    }
}
