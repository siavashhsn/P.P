namespace OS
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.add_tb = new System.Windows.Forms.TextBox();
            this.end_tb = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.add_btn = new System.Windows.Forms.Button();
            this.end_btn = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.runung_lb = new System.Windows.Forms.ListBox();
            this.blocked_lb = new System.Windows.Forms.ListBox();
            this.suspend_lb = new System.Windows.Forms.ListBox();
            this.finished_lb = new System.Windows.Forms.ListBox();
            this.ready_lb = new System.Windows.Forms.ListBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(630, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(61, 17);
            this.label1.TabIndex = 4;
            this.label1.Text = "Running";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(323, 20);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(144, 17);
            this.label5.TabIndex = 9;
            this.label5.Text = "Ready to run process";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(12, 20);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(96, 17);
            this.label6.TabIndex = 10;
            this.label6.Text = "Add Process :";
            // 
            // add_tb
            // 
            this.add_tb.Location = new System.Drawing.Point(15, 91);
            this.add_tb.MaximumSize = new System.Drawing.Size(170, 40);
            this.add_tb.MinimumSize = new System.Drawing.Size(150, 50);
            this.add_tb.Name = "add_tb";
            this.add_tb.Size = new System.Drawing.Size(170, 22);
            this.add_tb.TabIndex = 11;
            // 
            // end_tb
            // 
            this.end_tb.Location = new System.Drawing.Point(15, 183);
            this.end_tb.MaximumSize = new System.Drawing.Size(170, 40);
            this.end_tb.MinimumSize = new System.Drawing.Size(150, 50);
            this.end_tb.Name = "end_tb";
            this.end_tb.Size = new System.Drawing.Size(170, 22);
            this.end_tb.TabIndex = 12;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(12, 71);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(106, 17);
            this.label7.TabIndex = 13;
            this.label7.Text = "Process name :";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(12, 163);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(84, 17);
            this.label8.TabIndex = 14;
            this.label8.Text = "Process ID :";
            // 
            // add_btn
            // 
            this.add_btn.Location = new System.Drawing.Point(203, 91);
            this.add_btn.MaximumSize = new System.Drawing.Size(100, 40);
            this.add_btn.MinimumSize = new System.Drawing.Size(100, 50);
            this.add_btn.Name = "add_btn";
            this.add_btn.Size = new System.Drawing.Size(100, 50);
            this.add_btn.TabIndex = 15;
            this.add_btn.Text = "ADD";
            this.add_btn.UseVisualStyleBackColor = true;
            this.add_btn.Click += new System.EventHandler(this.add_btn_Click);
            // 
            // end_btn
            // 
            this.end_btn.Location = new System.Drawing.Point(203, 183);
            this.end_btn.MaximumSize = new System.Drawing.Size(100, 40);
            this.end_btn.MinimumSize = new System.Drawing.Size(100, 50);
            this.end_btn.Name = "end_btn";
            this.end_btn.Size = new System.Drawing.Size(100, 50);
            this.end_btn.TabIndex = 16;
            this.end_btn.Text = "END";
            this.end_btn.UseVisualStyleBackColor = true;
            this.end_btn.Click += new System.EventHandler(this.end_btn_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(630, 207);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(58, 17);
            this.label2.TabIndex = 5;
            this.label2.Text = "Blocked";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(630, 396);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(64, 17);
            this.label3.TabIndex = 6;
            this.label3.Text = "Suspend";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(633, 586);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(61, 17);
            this.label4.TabIndex = 7;
            this.label4.Text = "Finished";
            // 
            // runung_lb
            // 
            this.runung_lb.FormattingEnabled = true;
            this.runung_lb.ItemHeight = 16;
            this.runung_lb.Location = new System.Drawing.Point(633, 41);
            this.runung_lb.Name = "runung_lb";
            this.runung_lb.Size = new System.Drawing.Size(250, 164);
            this.runung_lb.TabIndex = 19;
            this.runung_lb.Click += new System.EventHandler(this.runung_lb_Click);
            this.runung_lb.SelectedIndexChanged += new System.EventHandler(this.runung_lb_SelectedIndexChanged);
            // 
            // blocked_lb
            // 
            this.blocked_lb.FormattingEnabled = true;
            this.blocked_lb.ItemHeight = 16;
            this.blocked_lb.Location = new System.Drawing.Point(633, 224);
            this.blocked_lb.Name = "blocked_lb";
            this.blocked_lb.Size = new System.Drawing.Size(250, 164);
            this.blocked_lb.TabIndex = 20;
            this.blocked_lb.Click += new System.EventHandler(this.blocked_lb_Click);
            this.blocked_lb.SelectedIndexChanged += new System.EventHandler(this.blocked_lb_SelectedIndexChanged);
            // 
            // suspend_lb
            // 
            this.suspend_lb.FormattingEnabled = true;
            this.suspend_lb.ItemHeight = 16;
            this.suspend_lb.Location = new System.Drawing.Point(636, 416);
            this.suspend_lb.Name = "suspend_lb";
            this.suspend_lb.Size = new System.Drawing.Size(247, 164);
            this.suspend_lb.TabIndex = 21;
            this.suspend_lb.Click += new System.EventHandler(this.suspend_lb_Click);
            this.suspend_lb.SelectedIndexChanged += new System.EventHandler(this.suspend_lb_SelectedIndexChanged);
            // 
            // finished_lb
            // 
            this.finished_lb.FormattingEnabled = true;
            this.finished_lb.ItemHeight = 16;
            this.finished_lb.Location = new System.Drawing.Point(636, 606);
            this.finished_lb.Name = "finished_lb";
            this.finished_lb.Size = new System.Drawing.Size(247, 164);
            this.finished_lb.TabIndex = 22;
            this.finished_lb.Click += new System.EventHandler(this.finished_lb_Click);
            this.finished_lb.SelectedIndexChanged += new System.EventHandler(this.finished_lb_SelectedIndexChanged);
            // 
            // ready_lb
            // 
            this.ready_lb.FormattingEnabled = true;
            this.ready_lb.ItemHeight = 16;
            this.ready_lb.Location = new System.Drawing.Point(326, 42);
            this.ready_lb.Name = "ready_lb";
            this.ready_lb.Size = new System.Drawing.Size(283, 724);
            this.ready_lb.TabIndex = 23;
            this.ready_lb.Click += new System.EventHandler(this.ready_lb_Click);
            this.ready_lb.SelectedIndexChanged += new System.EventHandler(this.ready_lb_SelectedIndexChanged);
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.textBox1.Location = new System.Drawing.Point(12, 239);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(291, 527);
            this.textBox1.TabIndex = 24;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(895, 778);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.ready_lb);
            this.Controls.Add(this.finished_lb);
            this.Controls.Add(this.suspend_lb);
            this.Controls.Add(this.blocked_lb);
            this.Controls.Add(this.runung_lb);
            this.Controls.Add(this.end_btn);
            this.Controls.Add(this.add_btn);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.end_tb);
            this.Controls.Add(this.add_tb);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox add_tb;
        private System.Windows.Forms.TextBox end_tb;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Button add_btn;
        private System.Windows.Forms.Button end_btn;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ListBox runung_lb;
        private System.Windows.Forms.ListBox blocked_lb;
        private System.Windows.Forms.ListBox suspend_lb;
        private System.Windows.Forms.ListBox finished_lb;
        private System.Windows.Forms.ListBox ready_lb;
        private System.Windows.Forms.TextBox textBox1;
    }
}

