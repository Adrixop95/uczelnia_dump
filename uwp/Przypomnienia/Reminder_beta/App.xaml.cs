using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.ApplicationModel;
using Windows.ApplicationModel.Activation;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using Windows.ApplicationModel.Background;
using Windows.UI.Core;

namespace Reminder_beta
{
    sealed partial class App : Application
    {
        public static List<ReminderData> ListOfData = new List<ReminderData>();
        public static string indeks1;

        public App()
        {
            this.InitializeComponent();
            this.Suspending += OnSuspending;
            RegisterRefreshTask();
        }

        protected override void OnLaunched(LaunchActivatedEventArgs e)
        {

#if DEBUG
            if (System.Diagnostics.Debugger.IsAttached)
            {
                this.DebugSettings.EnableFrameRateCounter = true;
            }
#endif

            Frame rootFrame = Window.Current.Content as Frame;
            if (rootFrame == null)
            {
                rootFrame = new Frame();

                rootFrame.NavigationFailed += OnNavigationFailed;
                rootFrame.Navigated += OnNavigated;

                Window.Current.Content = rootFrame;
                SystemNavigationManager.GetForCurrentView().BackRequested += OnBackRequested;

                SystemNavigationManager.GetForCurrentView().AppViewBackButtonVisibility =
                    rootFrame.CanGoBack ?
                    AppViewBackButtonVisibility.Visible :
                    AppViewBackButtonVisibility.Collapsed;
            }

            if (e.PrelaunchActivated == false)
            {
                if (rootFrame.Content == null)
                {
                    rootFrame.Navigate(typeof(MainPage), e.Arguments);
                }
                Window.Current.Activate();
            }
        }

        void OnNavigationFailed(object sender, NavigationFailedEventArgs e)
        {
            throw new Exception("Nie mozna zaladowac strony " + e.SourcePageType.FullName);
        }

        private void OnNavigated(object sender, NavigationEventArgs e)
        {
            SystemNavigationManager.GetForCurrentView().AppViewBackButtonVisibility =
                ((Frame)sender).CanGoBack ?
                AppViewBackButtonVisibility.Visible :
                AppViewBackButtonVisibility.Collapsed;
        }

        private async void OnSuspending(object sender, SuspendingEventArgs e)
        {
            var deferral = e.SuspendingOperation.GetDeferral();
            await SetupPage.SaveMyData(ListOfData);
            deferral.Complete();
        }

        private void OnBackRequested(object sender, BackRequestedEventArgs e)
        {
            Frame rootFrame = Window.Current.Content as Frame;

            if (rootFrame.CanGoBack )
            {
                e.Handled = true;
                rootFrame.GoBack();
            }
        }

        private void RegisterRefreshTask()
        {
            var taskRegistered = false;
            var TaskName = "Odswiez dane";

            foreach (var task in BackgroundTaskRegistration.AllTasks)
            {
                if (task.Value.Name == TaskName)
                {
                  task.Value.Unregister(true);
                   taskRegistered = true;
                    break;
                }
            }
            if (taskRegistered == false)
            {
                var check = BackgroundExecutionManager.RequestAccessAsync();
                TimeTrigger trigger = new TimeTrigger(1440,false);
                var taskBuldier = new BackgroundTaskBuilder();
                taskBuldier.Name = TaskName;
                taskBuldier.TaskEntryPoint = "Background.BTask";
                taskBuldier.SetTrigger(trigger);
                
                taskBuldier.Register();
            }
        }
    }
    
}
