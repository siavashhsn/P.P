using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace Client_GUI
{
    public partial class Form1 : Form
    {
        Socket sock;
        public Form1()
        {
            InitializeComponent();
            sock = socket();
        }

        Socket socket()
        {
            return new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        }

        private void connect_BTN_Click(object sender, EventArgs e)
        {
            try
            {
                sock.Connect(new IPEndPoint(IPAddress.Parse(textBox1.Text), 3));
                new Thread(delegate()
                    {
                        read();
                    }).Start();
            }
            catch
            {
                MessageBox.Show("CONNECTION FAILED!");
            }
        }
        void read()
        {
            while (true)
            {
                try
                {
                    byte[] buffer = new byte[255];
                    int rec = sock.Receive(buffer, 0, buffer.Length, 0);
                    if (rec <= 0)
                    {
                        throw new SocketException();
                    }

                    Array.Resize(ref buffer, rec);

                    Invoke((MethodInvoker)delegate
                    {
                        listBox1.Items.Add(Encoding.Default.GetString(buffer));
                    });
                }
                catch(SocketException)
                {
                    MessageBox.Show("DISCONNECTION Client From Server!");
                    //Application.Exit();
                }

            }
        }

        private void Send_BTN_Click(object sender, EventArgs e)
        {
            byte[] date = Encoding.Default.GetBytes(textBox2.Text);
            sock.Send(date, 0, date.Length, 0);
        }
    }
}
