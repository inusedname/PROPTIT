package test;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;

/**
 *
 * @author inusedname
 */
public class Test implements ActionListener {

    JTextField firstNumField, secondNumField, ansField;
    JButton add, subtract;

    Test() {
        JFrame f = new JFrame();
        firstNumField = new JTextField();
        secondNumField = new JTextField();
        ansField = new JTextField();
        firstNumField.setBounds(50, 50, 150, 20);
        secondNumField.setBounds(50, 100, 150, 20);
        ansField.setBounds(50, 150, 150, 20);
        ansField.setEditable(false);
        add = new JButton("+");
        subtract = new JButton("-");
        add.setBounds(50, 200, 50, 50);
        subtract.setBounds(120, 200, 50, 50);
        add.addActionListener(this);
        subtract.addActionListener(this);
        f.add(firstNumField);
        f.add(secondNumField);
        f.add(ansField);
        f.add(add);
        f.add(subtract);
        f.setSize(300, 300);
        f.setLayout(null);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        int a = Integer.parseInt(firstNumField.getText());
        int b = Integer.parseInt(secondNumField.getText());
        int c = 0;
        if (e.getSource() == add) {
            c = a + b;
        } else if (e.getSource() == subtract) {
            c = a - b;
        }
        ansField.setText(String.valueOf(c));
    }
    public static void main(String[] args) {
        new Test();
    }
};
