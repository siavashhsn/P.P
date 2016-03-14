using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO;

namespace test2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Button b = (Button)sender;
            TB.Text = TB.Text + b.Content.ToString();
        }
        string operation = "";
        double value = 0;
        private void Button_Click_Opertion(object sender, RoutedEventArgs e)
        {
            Button b = (Button)sender;
            operation = b.Content.ToString();
            //value = double.Parse(TB.Text);
            switch (operation)
            {
                case "+":
                    value += double.Parse(TB.Text);
                    break;
                case "-":
                    value -= double.Parse(TB.Text);
                    break;
                case "*":
                    value *= double.Parse(TB.Text);
                    break;
                case "/":
                    value /= double.Parse(TB.Text);
                    break;
                case "=":
                    break;
                case "C":
                    TB.Text = "";
                    label1.Content = "";
                    value = 0;
                    break;
                default :
                    break;
            }
            TB.Text = "";
            label1.Content = value.ToString();
        }
    }
}