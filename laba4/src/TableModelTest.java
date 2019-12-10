import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class TableModelTest extends JFrame {
    private DefaultTableModel tableModel;
    private JTable table1;
    private Object[][] array = new String[][]{
            {"Максим", "Андрей", "15.11.2019", "12min"},
            {"Антон", "Матвей", "05.11.2019", "2min"},
            {"Ждан", "Неждан", "11.11.2019", "25min"}
    };
    private Object[] columnsHeader = new String[]{"Кто звонил", "Кому звонил", "Дата", "Продолжительность"};

    public TableModelTest() {
        super("Журнал вызовов");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        tableModel = new DefaultTableModel();
        tableModel.setColumnIdentifiers(columnsHeader);
        // Наполнение модели данными
        for (int i = 0; i < array.length; i++)
            tableModel.addRow(array[i]);

        table1 = new JTable(tableModel);
        JButton add = new JButton("Добавить");
        add.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int idx = table1.getSelectedRow();
                tableModel.insertRow(idx + 1, new String[]{
                        "Кто", "Кому", "**.**.****", "min"});
            }
        });


        JButton remove = new JButton("Удалить");
        remove.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int idx = table1.getSelectedRow();
                tableModel.removeRow(idx);
            }
        });

        Box contents = new Box(BoxLayout.Y_AXIS);
        contents.add(new JScrollPane(table1));
        getContentPane().add(contents);

        JPanel buttons = new JPanel();
        buttons.add(add);
        buttons.add(remove);
        getContentPane().add(buttons, "South");
        setSize(400, 300);
        setVisible(true);
    }

    public static void main(String[] args) {
        new TableModelTest();
    }
}
