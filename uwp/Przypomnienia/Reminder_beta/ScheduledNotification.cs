using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.UI.Notifications;
using Windows.Data.Xml.Dom;


namespace Reminder_beta
{
   public class ScheduledNotification
    {
        private DateTimeOffset DateAndTime = new DateTimeOffset();
        private ReminderData Data = new ReminderData();
       
        public void CreateScheduledNotification()
        {
            string name = Data.Name;
            int quantity = Data.Quantity;
            string unit, beforeorafter;
            if (Data.Unit == 0)
            {
                unit = "ml";
            }
            else
            {
                if (Data.Unit == 1)
                    unit = "sztuk";
                else
                    unit = "g";
            }

            if (Data.beforeMeal == true && Data.afterMeal == false)
            {
                beforeorafter = "Przed posilkiem!";
            }
            else
            {
                if (Data.beforeMeal == true && Data.afterMeal == true)
                {
                    beforeorafter = "Mozesz je brac przed i po posilku.";
                }
                else
                {
                    if (Data.beforeMeal == false && Data.afterMeal == true)
                    {
                        beforeorafter = "Po Posilku";
                    }
                    else
                    {
                        beforeorafter = "-----------------";
                    }
                }
            }

            string xml = $@"<toast scenario=""przypomnienie"">
            <visual>
            <binding template=""ToastGeneric"">
                <text>{name}</text>
                <text>{quantity} {unit}</text>
                <text>{beforeorafter}</text>
                
            </binding>
            </visual>
            <actions>
            <input id=""snoozeTime"" type=""selection"" defaultInput=""10"">
                <selection id=""5"" content=""5 minut""/>
                <selection id=""10"" content=""10 minut""/>
                <selection id=""15"" content=""15 minut""/>
            </input>
            <action activationType=""system"" arguments=""snooze"" hint-inputId=""snoozeTime"" content=""""/>
            <action activationType=""system"" arguments=""dismiss"" content=""""/>
            </actions>
            <audio src = ""ms-appx:///Assets/toast.mp3"" loop = ""true""></audio>
            </toast>";
            XmlDocument doc = new XmlDocument();
            doc.LoadXml(xml);
            ScheduledToastNotification toast = new ScheduledToastNotification(doc,DateAndTime );
            toast.Tag = name;
            
            ToastNotificationManager.CreateToastNotifier().AddToSchedule(toast);

        }
        public void setEverything(ReminderData DataFromList)
        {
            DateTime now = DateTime.Now;
            DayOfWeek day = now.DayOfWeek;
            
            Data = DataFromList;
            foreach (DayOfWeek element in DataFromList.WeekDays)
            {
                DateAndTime = DateTimeOffset.Now;
                DateAndTime = DateAndTime.AddSeconds(-DateAndTime.Second);
                int i = day.CompareTo(element);
                if (i == -1)
                {
                    DateAndTime =DateAndTime.AddDays(element - day);
                }
                else
                {
                    if (i == 1)
                    {
                        DateAndTime = DateAndTime.AddDays(7 - (day - element));
                    }
                    else
                    {
                        if (DataFromList.Time.Hours <= now.Hour && DataFromList.Time.Minutes <= now.Minute )
                        {
                            DateAndTime = DateAndTime.AddDays(7);
                        }
                    }
                }
                if (DataFromList.Time.Hours.CompareTo(now.Hour) == -1)
                {
                    DateAndTime = DateAndTime.AddHours(DataFromList.Time.Hours - now.Hour);
                }
                else
                {
                    if (DataFromList.Time.Hours.CompareTo(now.Hour) == 1)
                    {
                        DateAndTime = DateAndTime.AddHours(DataFromList.Time.Hours - now.Hour);
                    }
                }

                if (DataFromList.Time.Minutes.CompareTo(now.Minute) == -1)
                {
                    DateAndTime = DateAndTime.AddMinutes(DataFromList.Time.Minutes - now.Minute);
                }
                else
                {
                    if (DataFromList.Time.Minutes.CompareTo(now.Minute) == 1)
                    {
                        DateAndTime = DateAndTime.AddMinutes(DataFromList.Time.Minutes - now.Minute);
                    }
                    else
                    {
                        DateAndTime = DateAndTime.AddMinutes(DataFromList.Time.Minutes);
                    }
                }
                CreateScheduledNotification();

            }
        } 
    }
}
