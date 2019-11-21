package ulsu.student.sayner;

import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.context.ApplicationContext;

@SpringBootApplication
public class Application {

    public static void main(String[] args) {
        ApplicationContext context = new SpringApplicationBuilder(Application.class)
                .headless(false)
                .run(args);
    }
}
