import com.gel.dao.Impl.UserDaoImpl;
import com.gel.po.User;
import org.junit.Test;

public class test {
    @Test
    public void test(){
        User user = new User();
        user.setUsername("zhangsan");
        new UserDaoImpl().getUserByUsername(user);
    }
}
