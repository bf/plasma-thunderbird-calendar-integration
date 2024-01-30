// see https://github.com/mdn/webextensions-examples/tree/main/native-messaging

/*
On startup, connect to the "ping_pong" app.
*/
let port = browser.runtime.connectNative("thunderbirdplasmaintegrationhostapp");

console.log("port", port)

var { calendar: lightning } = messenger;


lightning.calendars.onCreated.addListener((calendar) => {
  console.log("Created calendar", calendar);
});
lightning.calendars.onUpdated.addListener((calendar, changeInfo) => {
  console.log("Updated calendar", calendar, changeInfo);
});
lightning.calendars.onRemoved.addListener((id) => {
  console.log("Removed calendar", id);
});
lightning.items.onCreated.addListener((item) => {
  console.log("Created item", item);
}, { returnFormat: "ical" });
lightning.items.onUpdated.addListener((item, changeInfo) => {
  console.log("Updated item", item, changeInfo);
}, { returnFormat: "ical" });
lightning.items.onRemoved.addListener((calendarId, id) => {
  console.log("Deleted item", id);
});
lightning.items.onAlarm.addListener((item, alarm) => {
  console.log("Alarm item", item, alarm);
}, { returnFormat: "ical" });

function icalDate(date) {
  return date.toISOString().replace(/\.\d+Z$/, "").replace(/[:-]/g, "");
}

lightning.provider.onItemCreated.addListener(async (calendar, item) => {
  console.log("Provider add to calendar", item);
  item.metadata = { created: true };
  return item;
}, { returnFormat: "ical" });
lightning.provider.onItemUpdated.addListener(async (calendar, item, oldItem) => {
  console.log("Provider modify in calendar", item, oldItem);
  item.metadata = { updated: true };
  return item;
}, { returnFormat: "ical" });
lightning.provider.onItemRemoved.addListener(async (calendar, item) => {
  console.log("Provider remove from calendar", item);
});


// let ticks = {};
// lightning.provider.onInit.addListener(async (calendar) => {
//   console.log("Initializing", calendar);
// });
// lightning.provider.onSync.addListener(async (calendar) => {
//   console.log("Synchronizing", calendar, "tick", ticks[calendar.id]);

//   if (!ticks[calendar.id]) {
//     ticks[calendar.id] = 0;

//     await lightning.items.create(calendar.cacheId, {
//       id: "findme",
//       type: "event",
//       title: "New Event",
//       startDate: icalDate(new Date()),
//       endDate: icalDate(new Date()),
//       metadata: { etag: 123 }
//     });
//   } else if (ticks[calendar.id] == 1) {
//     await lightning.items.update(calendar.cacheId, "findme", {
//       title: "Updated",
//       startDate: icalDate(new Date()),
//       endDate: icalDate(new Date()),
//       metadata: { etag: 234 }
//     });
//   } else if (ticks[calendar.id] == 2) {
//     await lightning.calendars.clear(calendar.cacheId);
//   } else {
//     ticks[calendar.id] = -1;
//   }

//   ticks[calendar.id]++;
// });
// lightning.provider.onResetSync.addListener(async (calendar) => {
//   console.log("Reset sync for", calendar);
//   delete ticks[calendar.id];
// });

// // TODO - see comment in ext-calendar-provider.js. Provider should be registered after first tick so
// // onInit handler has a chance to execute, but before the async function is executed.
// setTimeout(async () => {
//   // let calendars = await lightning.calendars.query({ type: "ext-" + messenger.runtime.id });
//   // await Promise.all(calendars.map((calendar) => lightning.calendars.remove(calendar.id)));

//   // let calendar = await lightning.calendars.create({
//   //   type: "ext-" + messenger.runtime.id,
//   //   url: "custom://test",
//   //   name: "calendar ext"
//   // });
//   // console.log("create immediate", calendar);

//   // await lightning.calendars.update(calendar.id, { color: "#FF0000", readOnly: true });

//   // let calendar2 = await lightning.calendars.get(calendar.id);

//   // console.log("got calendar", calendar2);

//   // await lightning.calendars.synchronize();
//   // await new Promise(resolve => setTimeout(resolve, 500));

//   // let gotitem = await lightning.items.get(calendar2.id, "findme");
//   // console.log("Retrieved item", gotitem);

//   // let gotitems = await lightning.items.query({ calendarId: calendar2.id });
//   // console.log("Queried all items in calendar", gotitems);

//   // gotitems = await lightning.items.query({ id: "findme" });
//   // console.log("Queried all items with id findme", gotitems);

//   // gotitems = await lightning.items.query({ type: "task" });
//   // console.log("Queried all tasks (expect empty)", gotitems);

//   // gotitems = await lightning.items.query({ type: "event" });
//   // console.log("Queried all events (expect item)", gotitems);

//   // let rangeStartJs = new Date();
//   // let rangeEndJs = new Date();

//   // rangeEndJs.setFullYear(rangeEndJs.getFullYear() - 1);

//   // gotitems = await lightning.items.query({ rangeEnd: icalDate(rangeEndJs) });
//   // console.log("Queried past items (expect empty)", gotitems);

//   rangeStartJs = new Date();
//   rangeEndJs = new Date();
//   rangeStartJs.setMonth(rangeStartJs.getMonth() - 1);
//   rangeEndJs.setMonth(rangeEndJs.getMonth() + 1);

//   gotitems = await lightning.items.query({ type: "event", rangeStart: icalDate(rangeStartJs), rangeEnd: icalDate(rangeEndJs)});
//   // console.log("Queried within year range (expect item)", gotitems);

//   console.log(gotitems[0])
//   console.log(JSON.stringify(gotitems[0]))

//   // let [home, ...rest] = await lightning.calendars.query({ type: "storage" });
//   // console.log("queried calendars", home, rest);

//   // if (!home) {
//   //   home = await lightning.calendars.create({
//   //     type: "storage",
//   //     url: "moz-storage-calendar://",
//   //     name: "Home"
//   //   });
//   // }

//   // home.enabled = !home.enabled;
//   // await lightning.calendars.update(home.id, { enabled: home.enabled });

//   // if (home.enabled) {
//   //   let item = await lightning.items.create(home.id, { type: "event", title: "hello", location: "here", categories: ["Birthdays"], returnFormat: "ical" });
//   //   console.log("Created item", item, home);

//   //   let updated = await lightning.items.update(home.id, item.id, { title: "world" });
//   //   console.log("Updated item", updated);


//   //   await new Promise(resolve => setTimeout(resolve, 500));
//   //   // Moving & Removing
//   //   let home2 = await lightning.calendars.create({
//   //     type: "storage",
//   //     url: "moz-storage-calendar://",
//   //     name: "temp move",
//   //     color: "#00FF00"
//   //   });


//   //   await lightning.items.move(home.id, item.id, home2.id);
//   //   await new Promise(resolve => setTimeout(resolve, 1000));
//   //   await lightning.items.remove(home2.id, item.id);

//   //   await lightning.calendars.remove(home2.id);
//   // }

//   await new Promise(resolve => setTimeout(resolve, 2000));
// }, 2000);

/*
Listen for messages from the app.
*/
port.onMessage.addListener((message) => {
  console.log("PORT Received message:", message);

  switch (message.action) {
    case "search":
      const fromDate = message.from
      const toDate = message.to
      console.log("search fromDate", fromDate, "toDate", toDate)
      searchEventsInDateRange(fromDate, toDate)
      break;

  default:
    console.error("no such message.action", message)
  }
});


async function searchEventsInDateRange(fromDate, toDate) {
  console.log("searchEventsInDateRange", fromDate, toDate)

  const strFromDate = (""+fromDate)
  const strToDate = (""+toDate)

  const intFromYear = parseInt(strFromDate.substr(0,4), 10)
  const intFromMonth = parseInt(strFromDate.substr(4,2), 10) - 1
  const intFromDay = parseInt(strFromDate.substr(6, 2), 10)

  if (isNaN(intFromYear) || isNaN(intFromMonth) || isNaN(intFromDay)) {
    console.error("searchEventsInDateRange invalid fromDate", strFromDate)
    return
  }

  const intToYear = parseInt(strToDate.substr(0,4), 10)
  const intToMonth = parseInt(strToDate.substr(4,2), 10) - 1
  const intToDay = parseInt(strToDate.substr(6, 2), 10)

  if (isNaN(intToYear) || isNaN(intToMonth) || isNaN(intToDay)) {
    console.error("searchEventsInDateRange invalid toDate", strToDate)
    return
  }

  rangeStartJs = new Date(intFromYear, intFromMonth, intFromDay)
  rangeEndJs = new Date(intToYear, intToMonth, intToDay)
  console.log("rangeStartJs", rangeStartJs, "rangeEndJs", rangeEndJs)

  if (rangeStartJs >= rangeEndJs) {
    console.error("rangeStartJs needs to be larger than rangeEndJs")
    return
  }

  const events = await lightning.items.query({ 
    type: "event", 
    rangeStart: icalDate(rangeStartJs), 
    rangeEnd: icalDate(rangeEndJs)
  });

  console.log("searchEventsInDateRange found events", events)

  const arrEvents = []
  events.map(function (item) {
    arrEvents.push([
      item.id, 
      item.title.trim(), 
      item.calendarId, 
      calendarColors[item.calendarId],
      item.startDate,
      item.endDate
    ])
  })

    console.log("searchEventsInDateRange arrEvents return", arrEvents)
    
  // return results
 sendMessageToNativeScript({ fromDate, toDate, events: arrEvents })
}

function sendMessageToNativeScript(data) {
  console.log("sendMessageToNativeScript", data)
   port.postMessage(data)
}

let calendarColors = {}

async function loadCalendars() {
  console.log("loadCalendars")
  const rawCalendars = await lightning.calendars.query({ enabled: true })
  console.log("loadCalendars result", rawCalendars)


  calendars = []
  rawCalendars.forEach(function (calendar) {
    calendars.push([
      calendar.id,
      calendar.name,
      calendar.color
    ])

    calendarColors[calendar.id] = calendar.color
  })

  sendMessageToNativeScript({ calendars })
  // sendMessageToNativeScript("ping")
}

// load calendars and send to native script
loadCalendars()


// port.postMessage("thunderbird-is-ready");

/*
On a click on the browser action, send the app a message.
*/
browser.action.onClicked.addListener(() => {
  console.log("Sending:  ping");
  sendMessageToNativeScript("ping");
});