  // ***********************************************************
  // REQUIRED CONSTANTS, DO NOT MODIFY
  // ***********************************************************
  var ASSIGNMENT_MARKING = 'Assignment Marking';
  var COURSE_MATERIAL_PREPARATION = 'Course Material Preparation';
  var TUTORIAL = 'Tutorial';
  var CONSULTATION = 'Consultation with students';
  var LABORATORY = 'Laboratory';
  var POST_URL = '/~tssclaim/tutor/teach_claim.php';
  var END_REDIRECT_URL = '/~tssclaim/tutor/teach_claim.php?page=list';

  // ***********************************************************
  // READ THE FOLLOWING BEFORE STARTING
  // ***********************************************************
  // 1. **IMPORTANT STEP** Change the properties in the config object in the next section.
  //    - NUMBER_OF_STUDENTS
  //    - NUMBER_OF_TUTORIALS
  //    - student_id


  // 2. Login to the portal at: https://mysoc.nus.edu.sg/~tssclaim/. Fill in your bank account information if you haven't.

  // 3. Access the page titled 'Student Claim Submission' (https://mysoc.nus.edu.sg/~tssclaim/tutor/teach_claim.php?page=1) and click on
  //    the 'Claim' button under your module. You should see the interface for you to enter details of the teaching claim activity.

  // 4. Open the JS console (Ctrl/Cmd + Shift/Option + J), paste all the code in this file in the JS console and press enter. You should
  //    see the message 'Claim object successfully created. Run c.makeAllClaims() to start.'.

  // 5. Run the function c.makeAllClaims() . Wait until the alert 'All claims made!' is shown, then press 'OK'.

  // 6. You will be brought back to the previous page. Click on the button 'Claim' again and verify that you have 80 hours in total.

  // To delete all claims on the page, run the function c.deleteAllClaims()


  // ***********************************************************
  // CONFIGURE THE RELEVANT PROPERTIES IN THE CONFIG OBJECT
  // ***********************************************************
  var STUDENT_ID = 'e0123456';
  var NUMBER_OF_STUDENTS = 12;
  var WEEK_1_GRADING_STUDENTS = 12; // fill in the Week 1 Grading Students
  var NUMBER_OF_TUTORIALS = 1;
  var TIME_CONST = 20;

  // We are only using the hour and minutes for the tutorial time calculation
  var GRADING_START_TIME = new Date('AUG 17, 2020, 11:00:00');
  var GRADING_END_TIME = new Date(GRADING_START_TIME);
  // Round up timings to 30 minute intervals
  GRADING_END_TIME.setMinutes(
  	Math.ceil((GRADING_END_TIME.getMinutes() + NUMBER_OF_STUDENTS * TIME_CONST)/30) * 30
  );
  var padZeros = function(x, l) { if (x.length < l) { return padZeros('0'+x, l); } return x;}
  var dateString = function(d) { return padZeros(d.getHours()+'',2) + padZeros(d.getMinutes()+'', 2); }
  var grading_start_string = dateString(GRADING_START_TIME);
  var grading_end_string = dateString(GRADING_END_TIME);
  console.log(grading_start_string);
  console.log(grading_end_string);

  var config = {
    // Format: YYYY/MM/DD
    // Note: Month is from 0-11, Date is from 1-31
    // This should be the semester's week 1. For AY13/14 Sem 1, it's Monday, Aug 12
    first_day_of_sem: new Date(2021, 0, 11),
    // the id you use to log in to the portal
    student_id: STUDENT_ID,
    // module you are claiming hours for
    module: 'CS2040C',
    // in case you want to customize the duties field for each activity
    duties: {
      'Assignment Marking': 'Graded Assignment',
      'Course Material Preparation': 'Prepared course materials',
      'Tutorial': 'Conducted tutorial',
      'Consultation with students': 'Had consultation with students',
      'Laboratory': 'Prepared and tutored laboratory',
    },

    // the following function should return a list of claim objects that you want to make
    activities_list_fn: function() {
      var claims_list = [];

      // Weekly stuff
      // Tutorials: 11 x 1h class = 11h
      // Marking: 12 x 20mins x NUMBER_OF_STUDENTS

      var week_1_grading_end_time = new Date(GRADING_START_TIME);
      week_1_grading_end_time.setMinutes(
        Math.ceil((week_1_grading_end_time.getMinutes() + WEEK_1_GRADING_STUDENTS * TIME_CONST)/30) * 30
      );

      for (var week = 3; week <= 13; week++) {
        claims_list.push({
          activity_type: LABORATORY,
          week: week,
          day: "WEDNESDAY",
          start_time: '1600',
          end_time: '1800',
          // end_time: (10 + NUMBER_OF_TUTORIALS) + '00'
        });
      };

      // Assignments 1-5 + PE
      for (var aNo = 1; aNo <= 6; ++aNo) {
        claims_list.push({
          activity_type: ASSIGNMENT_MARKING,
          week: aNo + 7,
          day: "SUNDAY",
          start_time: '0800',
          end_time: '1200',
        });
      }

      return claims_list;
    }
  }


  // ***********************************************************
  // DO NOT CHANGE THE BOTTOM UNLESS YOU KNOW WHAT YOU ARE DOING
  // ***********************************************************

  var ACTIVITY_DICT = {};
  ACTIVITY_DICT[ASSIGNMENT_MARKING] = '003';
  ACTIVITY_DICT[COURSE_MATERIAL_PREPARATION] = '006';
  ACTIVITY_DICT[TUTORIAL] = 'T';
  ACTIVITY_DICT[CONSULTATION] = 'C';
  ACTIVITY_DICT[LABORATORY] = 'B';

  var DAY_DICT = { 'MONDAY': 0, 'TUESDAY': 1, 'WEDNESDAY': 2, 'THURSDAY': 3, 'FRIDAY': 4, 'SATURDAY': 5, 'SUNDAY': 6 };

  function Claim(config) {
    this.student_id = config.student_id.toLowerCase();
    this.module = config.module;
    this.remarks = config.duties;
    this.first_day_of_sem = config.first_day_of_sem;
    this.error = false;
    var that = this;
    function createActivity(activity_type, week, day, start_time, end_time) {
      // obj has the properties:
      var day_upper = day.toUpperCase();
      try {
        if (ACTIVITY_DICT[activity_type] == undefined || typeof activity_type != "string") {
          throw "Activity error: " + activity_type + ". Activity type not supported.";
        }
        if (typeof week != "number" || week <= 0) {
          throw "Week error: " + week + ". Week value has to be a positive number.";
        }
        if (DAY_DICT[day_upper] == undefined || typeof day_upper != "string") {
          throw "Day error: " + day + ". Day value has to be a valid day string.";
        }
        function checkTime(time) {
          var start_time_hour = time.slice(0,2);
          var start_time_min = time.slice(2);
          if (typeof time != "string" ||
            time.length != 4 ||
            !(parseInt(start_time_hour) >= 0 && parseInt(start_time_hour) <= 23) ||
            !(start_time_min == "00" || start_time_min == "30")) {
            throw "Time error: " + time + ". Time has to be string in 24-hr format at half-hour intervals.";
          }
        }
        checkTime(start_time);
        checkTime(end_time);
        console.log('start time', start_time);
        var start_time_hour = parseInt(start_time.slice(0,2));
        var end_time_hour = parseInt(end_time.slice(0,2));
        if (start_time_hour > end_time_hour || start_time === end_time) {
          throw "Time error: end_time: " + end_time + " must be after start_time: " + start_time + ".";
        } else if (end_time_hour - start_time_hour > 8) {
          throw "Time error: " + start_time + " - " + end_time + ". Activity cannot be more than 8 hours.";
        }
      } catch (err) {
        error = true;
        console.log(err);
      }
      return function() {
        that.makeClaim(activity_type, week, day, start_time, end_time);
      };
    }
    var activities = config.activities_list_fn();
    this.activities_list = [];
    for (var i = 0; i < activities.length; i++) {
      var a = activities[i];
      this.activities_list.push(createActivity(a.activity_type, a.week, a.day, a.start_time, a.end_time));
    }

    this.ajax_index = 0; // index to keep track of the current ajax call
    console.log('Claim object successfully created. Run c.makeAllClaims() to start.');
  }

  Claim.prototype.makeClaim = function(activity_type, week, day, start_time, end_time) {
    var day_num = DAY_DICT[day];
    var number_of_days = (week < 7 ? week - 1 : week)*7 + day_num;
    var activity_date = new Date();
    activity_date.setTime(this.first_day_of_sem.getTime() + (number_of_days * 24 * 60 * 60 * 1000));
    var claim_date_array = activity_date.toDateString().split(' ');
    var claim_date_str = [claim_date_array[2], claim_date_array[1], claim_date_array[3].slice(2)].join('-');

    var post_data = {
      mod_c: this.module,
      action: 'ADD',
      std_id: this.student_id,
      activity_c: ACTIVITY_DICT[activity_type],
      remarks: this.remarks[activity_type],
      claim_date: claim_date_str,
      start_time_hr: start_time.slice(0,2),
      start_time_min: start_time.slice(2),
      end_time_hr: end_time.slice(0,2),
      end_time_min: end_time.slice(2),
      submit: 'ADD + Save as Draft'
    }

    var that = this;
    $.post(POST_URL, post_data, function(data) {
      console.log('Successfully added ' + activity_type + ' for ' + claim_date_str);
      that.ajax_index += 1;
      if (that.ajax_index < that.activities_list.length) {
        that.activities_list[that.ajax_index]();
      } else {
        alert('All claims made! Press OK to continue.');
        // redirect to previous page because a refresh of the page would trigger the last ajax call
        window.location.href = window.location.protocol +'//'+ window.location.host + END_REDIRECT_URL;
      }
    });
  };

  Claim.prototype.deleteAllClaims = function() {
    var that = this;
    function deleteClaim(claim_id) {
      $.post(POST_URL, {
        mod_c: that.module,
        claim_id: claim_id,
        action: 'DELETE',
        std_id: that.student_id,
        submit: 'DELETE + Save as Draft'
      }, function(data) {
        console.log('Claim ' + claim_id + ' deleted');
        count += 1;
        if (count === $existing_claims.length) {
          alert('All claims deleted! Press OK to continue.');
          window.location.href = window.location.protocol +'//'+ window.location.host + END_REDIRECT_URL;
        }
      });
    }
    var count = 0;
    var $existing_claims = $('#claim-info-div table [name="claim_id"]');
    $existing_claims.each(function() {
      deleteClaim(this.value);
    });
  }

  Claim.prototype.makeAllClaims = function() {
    if (!this.error) {
      this.activities_list[this.ajax_index]();
    }
  }

  var c = new Claim(config);
  // c.deleteAllClaims();

  c.makeAllClaims();