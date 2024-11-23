import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

/**
 * Main window class that extends JFrame.
 */
public class Window extends JFrame {
    JTextArea textArea;
    ButtonPanel buttonPanel;
    MenuBar menuBar;
    Client client;
    /**
     * Constructor for the Window class.
     */
    public Window() {
        super("Window");

        try {
            client = new Client("localhost", 3331);
        }
        catch (Exception e) {
            System.err.println("Client: Couldn't connect to localhost:3331");
            System.exit(1);
        }

        buttonPanel = new ButtonPanel();
        menuBar = new MenuBar();
        textArea = new JTextArea(20, 60);

        add(buttonPanel, BorderLayout.SOUTH);
        add(textArea, BorderLayout.CENTER);
        setJMenuBar(menuBar);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        pack();

        setVisible(true);
    }

    /**
     * Main method to run the application.
     * @param args Command line arguments.
     */
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new Window();
            }
        });
    }

    /**
     * MenuBar class that extends JMenuBar.
     */
    class MenuBar extends JMenuBar {
        JMenu menu;
        JToolBar toolBar;

        /**
         * Constructor for the MenuBar class.
         */
        public MenuBar() {
            menu = new JMenu("File");
            toolBar = new JToolBar();

            // Create actions
            Action infoAction = new InfoAction();
            Action playAction = new PlayAction();
            Action closeAction = new CloseAction();

            // Add actions to menu
            menu.add(new JMenuItem(infoAction));
            menu.add(new JMenuItem(playAction));
            menu.add(new JMenuItem(closeAction));

            // Add actions to toolbar
            toolBar.add(infoAction);
            toolBar.add(playAction);
            toolBar.add(closeAction);

            add(menu);
            add(toolBar, BorderLayout.NORTH);
        }
    }

    /**
     * ButtonPanel class that extends JPanel.
     */
    class ButtonPanel extends JPanel {
        JButton button1;
        JButton button2;
        JButton button3;

        /**
         * Constructor for the ButtonPanel class.
         */
        public ButtonPanel() {
            // Create actions
            Action infoAction = new InfoAction();
            Action playAction = new PlayAction();
            Action closeAction = new CloseAction();

            // Create buttons with actions
            button1 = new JButton(infoAction);
            button2 = new JButton(playAction);
            button3 = new JButton(closeAction);

            add(button1);
            add(button2);
            add(button3);
        }
    }

    /**
     * InfoAction class that extends AbstractAction.
     */
    class InfoAction extends AbstractAction {
        public InfoAction() {
            putValue(NAME, "Info");
        }

        public void actionPerformed(ActionEvent e) {
            String[] options = {"Object", "Group"};
            int choice = JOptionPane.showOptionDialog(
                null, 
                "Choose type:", 
                "Info", 
                JOptionPane.DEFAULT_OPTION, 
                JOptionPane.INFORMATION_MESSAGE, 
                null, 
                options, 
                options[0]
            );
            if (choice >= 0) {
                String type = options[choice];
                String name = JOptionPane.showInputDialog("Enter name:");
                if (name != null && !name.isEmpty()) {
                    String response = client.send("info " + type.toLowerCase() + " " + name);
                    textArea.append(response + "\n");
                }
            }
        }
    }

    /**
     * PlayAction class that extends AbstractAction.
     */
    class PlayAction extends AbstractAction {
        public PlayAction() {
            putValue(NAME, "Play");
        }

        public void actionPerformed(ActionEvent e) {
            String name = JOptionPane.showInputDialog("Enter name:");
            if (name != null && !name.isEmpty()) {
                String response = client.send("play " + name);
                textArea.append(response + "\n");
            }
        }
    }
    /**
     * CloseAction class that extends AbstractAction.
     */
    class CloseAction extends AbstractAction {
        /**
         * Constructor for the CloseAction class.
         */
        public CloseAction() {
            putValue(NAME, "Close");
        }

        /**
         * Method called when the action is performed.
         * @param e ActionEvent object.
         */
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }
}