package ulsu.student.sayner.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class HomeController {

    @GetMapping("/blank")
    public String getBlankPage(){
        return "blank";
    }
}
