namespace Database_Project__store_
{
    partial class Backup_RestoreForm
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
            this.backup_Btn = new System.Windows.Forms.Button();
            this.restore_Btn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // backup_Btn
            // 
            this.backup_Btn.Location = new System.Drawing.Point(29, 32);
            this.backup_Btn.Name = "backup_Btn";
            this.backup_Btn.Size = new System.Drawing.Size(116, 56);
            this.backup_Btn.TabIndex = 0;
            this.backup_Btn.Text = "Backup";
            this.backup_Btn.UseVisualStyleBackColor = true;
            this.backup_Btn.Click += new System.EventHandler(this.backup_Btn_Click);
            // 
            // restore_Btn
            // 
            this.restore_Btn.Location = new System.Drawing.Point(196, 32);
            this.restore_Btn.Name = "restore_Btn";
            this.restore_Btn.Size = new System.Drawing.Size(116, 56);
            this.restore_Btn.TabIndex = 1;
            this.restore_Btn.Text = "Restore";
            this.restore_Btn.UseVisualStyleBackColor = true;
            this.restore_Btn.Click += new System.EventHandler(this.restore_Btn_Click);
            // 
            // Backup_RestoreForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(347, 121);
            this.Controls.Add(this.restore_Btn);
            this.Controls.Add(this.backup_Btn);
            this.Name = "Backup_RestoreForm";
            this.Text = "Backup_RestoreForm";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button backup_Btn;
        private System.Windows.Forms.Button restore_Btn;
    }
}