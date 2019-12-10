import javax.swing.table.AbstractTableModel;

class SimpleModel extends AbstractTableModel
{
    @Override
    public int getRowCount() {
        return 10;
    }

    @Override
    public int getColumnCount() {
        return 4;
    }

    @Override
    public Object getValueAt(int row, int column) {
        return 0;
    }
}
