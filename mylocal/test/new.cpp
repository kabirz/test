namespace testing
{
  using internal::CountIf;
  using internal::ForEach;
  using internal::GetElementOr;
  using internal::Shuffle;
  static const char kDisableTestFilter[] = "DISABLED_*:*/DISABLED_*";
  static const char kDeathTestCaseFilter[] = "*DeathTest:*DeathTest/*";
  static const char kUniversalFilter[] = "*";
  static const char kDefaultOutputFile[] = "test_detail.xml";
  static const char kTestShardIndex[] = "GTEST_SHARD_INDEX";
  static const char kTestTotalShards[] = "GTEST_TOTAL_SHARDS";
  static const char kTestShardStatusFile[] = "GTEST_SHARD_STATUS_FILE";
  namespace internal
  {
    const char kStackTraceMarker[] = "\nStack trace:\n";
    bool g_help_flag = false;
  }
  bool FLAGS_gtest_also_run_disabled_tests =
    (internal::BoolFromGTestEnv ("also_run_disabled_tests", false));
  bool FLAGS_gtest_break_on_failure =
    (internal::BoolFromGTestEnv ("break_on_failure", false));
  bool FLAGS_gtest_catch_exceptions =
    (internal::BoolFromGTestEnv ("catch_exceptions", true));
  ::testing::internal::String FLAGS_gtest_color =
    (internal::StringFromGTestEnv ("color", "auto"));
  ::testing::internal::String FLAGS_gtest_filter =
    (internal::StringFromGTestEnv ("filter", kUniversalFilter));
  bool FLAGS_gtest_list_tests = (false);
  ::testing::internal::String FLAGS_gtest_output =
    (internal::StringFromGTestEnv ("output", ""));
  bool FLAGS_gtest_print_time =
    (internal::BoolFromGTestEnv ("print_time", true));
  ::testing::internal::Int32 FLAGS_gtest_random_seed =
    (internal::Int32FromGTestEnv ("random_seed", 0));
  ::testing::internal::Int32 FLAGS_gtest_repeat =
    (internal::Int32FromGTestEnv ("repeat", 1));
  bool FLAGS_gtest_show_internal_stack_frames = (false);
  bool FLAGS_gtest_shuffle = (internal::BoolFromGTestEnv ("shuffle", false));
  ::testing::internal::Int32 FLAGS_gtest_stack_trace_depth =
    (internal::Int32FromGTestEnv ("stack_trace_depth", kMaxStackTraceDepth));
  ::testing::internal::String FLAGS_gtest_stream_result_to =
    (internal::StringFromGTestEnv ("stream_result_to", ""));
  bool FLAGS_gtest_throw_on_failure =
    (internal::BoolFromGTestEnv ("throw_on_failure", false));
  namespace internal
  {
    UInt32 Random::Generate (UInt32 range)
    {
      state_ = (1103515245U * state_ + 12345U) % kMaxRange;
      switch (0)
	case 0:
	default:
	if (::testing::internal::IsTrue (range > 0));
	else
	  ::testing::internal::GTestLog (::testing::internal::GTEST_FATAL,
					 "gtest.cc",
					 288).GetStream () << "Condition "
	    "range > 0" " failed. " <<
	    "Cannot generate a number in the range [0, 0).";
      switch (0)
	case 0:
	default:
	if (::testing::internal::IsTrue (range <= kMaxRange));
	else
	  ::testing::internal::GTestLog (::testing::internal::GTEST_FATAL,
					 "gtest.cc",
					 290).GetStream () << "Condition "
	    "range <= kMaxRange" " failed. " <<
	    "Generation of a number in [0, " << range << ") was requested, "
	    << "but this can only generate numbers in [0, " << kMaxRange <<
	    ").";
      return state_ % range;
    }
    int g_init_gtest_count = 0;
    static bool GTestIsInitialized ()
    {
      return g_init_gtest_count != 0;
    }
    static int SumOverTestCaseList (const std::vector <
				    TestCase * >&case_list,
				    int (TestCase::*method) ()const)
    {
      int sum = 0;
      for (size_t i = 0; i < case_list.size (); i++)
	{
	  sum += (case_list[i]->*method) ();
	}
      return sum;
    }
    static bool TestCasePassed (const TestCase * test_case)
    {
      return test_case->should_run () && test_case->Passed ();
    }
    static bool TestCaseFailed (const TestCase * test_case)
    {
      return test_case->should_run () && test_case->Failed ();
    }
    static bool ShouldRunTestCase (const TestCase * test_case)
    {
      return test_case->should_run ();
    }
  AssertHelper::AssertHelper (TestPartResult::Type type, const char *file, int line, const char *message):data_ (new
	   AssertHelperData (type, file, line,
			     message))
    {
    }
    AssertHelper::~AssertHelper ()
    {
      delete data_;
    }
    void AssertHelper::operator= (const Message & message) const
    {
      UnitTest::GetInstance ()->AddTestPartResult (data_->type, data_->file,
						   data_->line,
						   AppendUserMessage
						   (data_->message, message),
						   UnitTest::GetInstance ()->
						   impl ()->
						   CurrentOsStackTraceExceptTop
						   (1));
    }
    ::testing::internal::MutexBase g_linked_ptr_mutex =
    {
      {
	{
	  0, 0, 0, 0, 0, 0,
	  {
    0, 0}}}, 0};
    String g_executable_path;
    FilePath GetCurrentExecutableName ()
    {
      FilePath result;
      result.Set (FilePath (g_executable_path));
      return result.RemoveDirectoryName ();
    }
    String UnitTestOptions::GetOutputFormat ()
    {
      const char *const gtest_output_flag = FLAGS_gtest_output.c_str ();
      if (gtest_output_flag == __null)
	return String ("");
      const char *const colon = strchr (gtest_output_flag, ':');
      return (colon == __null) ?
	String (gtest_output_flag) :
	String (gtest_output_flag, colon - gtest_output_flag);
    }
    String UnitTestOptions::GetAbsolutePathToOutputFile ()
    {
      const char *const gtest_output_flag = FLAGS_gtest_output.c_str ();
      if (gtest_output_flag == __null)
	return String ("");
      const char *const colon = strchr (gtest_output_flag, ':');
      if (colon == __null)
	return String (internal::FilePath::ConcatPaths (internal::FilePath
							(UnitTest::GetInstance
							 ()->
							 original_working_dir
							 ()),
							internal::
							FilePath
							(kDefaultOutputFile)).
		       ToString ());
      internal::FilePath output_name (colon + 1);
      if (!output_name.IsAbsolutePath ())
	output_name =
	  internal::FilePath::ConcatPaths (internal::FilePath
					   (UnitTest::GetInstance
					    ()->original_working_dir ()),
					   internal::FilePath (colon + 1));
      if (!output_name.IsDirectory ())
	return output_name.ToString ();
      internal::FilePath result (internal::FilePath::GenerateUniqueFileName
				 (output_name,
				  internal::GetCurrentExecutableName (),
				  GetOutputFormat ().c_str ()));
      return result.ToString ();
    }
    bool UnitTestOptions::PatternMatchesString (const char *pattern,
						const char *str)
    {
      switch (*pattern)
	{
	case '\0':
	case ':':
	  return *str == '\0';
	case '?':
	  return *str != '\0' && PatternMatchesString (pattern + 1, str + 1);
	case '*':
	  return (*str != '\0' && PatternMatchesString (pattern, str + 1)) ||
	    PatternMatchesString (pattern + 1, str);
	default:
	  return *pattern == *str &&
	    PatternMatchesString (pattern + 1, str + 1);
	}
    }
    bool UnitTestOptions::MatchesFilter (const String & name,
					 const char *filter)
    {
      const char *cur_pattern = filter;
      for (;;)
	{
	  if (PatternMatchesString (cur_pattern, name.c_str ()))
	    {
	      return true;
	    }
	  cur_pattern = strchr (cur_pattern, ':');
	  if (cur_pattern == __null)
	    {
	      return false;
	    }
	  cur_pattern++;
	}
    }
    bool UnitTestOptions::FilterMatchesTest (const String & test_case_name,
					     const String & test_name)
    {
      const String & full_name = String::Format ("%s.%s",
						 test_case_name.c_str (),
						 test_name.c_str ());
      const char *const p = FLAGS_gtest_filter.c_str ();
      const char *const dash = strchr (p, '-');
      String positive;
      String negative;
      if (dash == __null)
	{
	  positive = FLAGS_gtest_filter.c_str ();
	  negative = String ("");
	}
      else
	{
	  positive = String (p, dash - p);
	  negative = String (dash + 1);
	  if (positive.empty ())
	    {
	      positive = kUniversalFilter;
	    }
	}
      return (MatchesFilter (full_name, positive.c_str ()) &&
	      !MatchesFilter (full_name, negative.c_str ()));
    }
  }
ScopedFakeTestPartResultReporter::ScopedFakeTestPartResultReporter (TestPartResultArray * result):intercept_mode_ (INTERCEPT_ONLY_CURRENT_THREAD),
    result_
    (result)
  {
    Init ();
  }
ScopedFakeTestPartResultReporter::ScopedFakeTestPartResultReporter (InterceptMode intercept_mode, TestPartResultArray * result):intercept_mode_ (intercept_mode),
    result_
    (result)
  {
    Init ();
  }
  void ScopedFakeTestPartResultReporter::Init ()
  {
    internal::UnitTestImpl * const impl = internal::GetUnitTestImpl ();
    if (intercept_mode_ == INTERCEPT_ALL_THREADS)
      {
	old_reporter_ = impl->GetGlobalTestPartResultReporter ();
	impl->SetGlobalTestPartResultReporter (this);
      }
    else
      {
	old_reporter_ = impl->GetTestPartResultReporterForCurrentThread ();
	impl->SetTestPartResultReporterForCurrentThread (this);
      }
  }
  ScopedFakeTestPartResultReporter::~ScopedFakeTestPartResultReporter ()
  {
    internal::UnitTestImpl * const impl = internal::GetUnitTestImpl ();
    if (intercept_mode_ == INTERCEPT_ALL_THREADS)
      {
	impl->SetGlobalTestPartResultReporter (old_reporter_);
      }
    else
      {
	impl->SetTestPartResultReporterForCurrentThread (old_reporter_);
      }
  }
  void ScopedFakeTestPartResultReporter::ReportTestPartResult (const
							       TestPartResult
							       & result)
  {
    result_->Append (result);
  }
  namespace internal
  {
    TypeId GetTestTypeId ()
    {
      return GetTypeId < Test > ();
    }
    extern const TypeId kTestTypeIdInGoogleTest = GetTestTypeId ();
    AssertionResult HasOneFailure (const char *,
				   const char *,
				   const char *,
				   const TestPartResultArray & results,
				   TestPartResult::Type type,
				   const string & substr)
    {
      const String expected (type == TestPartResult::kFatalFailure ?
			     "1 fatal failure" : "1 non-fatal failure");
      Message msg;
      if (results.size () != 1)
	{
	  msg << "Expected: " << expected << "\n"
	    << "  Actual: " << results.size () << " failures";
	  for (int i = 0; i < results.size (); i++)
	    {
	      msg << "\n" << results.GetTestPartResult (i);
	    }
	  return AssertionFailure () << msg;
	}
      const TestPartResult & r = results.GetTestPartResult (0);
      if (r.type () != type)
	{
	  return AssertionFailure () << "Expected: " << expected << "\n"
	    << "  Actual:\n" << r;
	}
      if (strstr (r.message (), substr.c_str ()) == __null)
	{
	  return AssertionFailure () << "Expected: " << expected <<
	    " containing \"" << substr << "\"\n" << "  Actual:\n" << r;
	}
      return AssertionSuccess ();
    }
  SingleFailureChecker::SingleFailureChecker (const TestPartResultArray * results, TestPartResult::Type type, const string & substr):results_ (results),
      type_ (type),
      substr_ (substr)
    {
    }
    SingleFailureChecker::~SingleFailureChecker ()
    {
      switch (0)
	case 0:
	default:
	if (const::testing::AssertionResult gtest_ar =
	    (HasOneFailure
	     ("*results_", "type_", "substr_", *results_, type_, substr_)));
	else
	  ::testing::internal::AssertHelper (::testing::TestPartResult::
					     kNonFatalFailure, "gtest.cc",
					     657,
					     gtest_ar.
					     failure_message ()) =::testing::
	    Message ();
    }
  DefaultGlobalTestPartResultReporter::DefaultGlobalTestPartResultReporter (UnitTestImpl * unit_test):unit_test_
      (unit_test)
    {
    }
    void DefaultGlobalTestPartResultReporter::ReportTestPartResult (const
								    TestPartResult
								    & result)
    {
      unit_test_->current_test_result ()->AddTestPartResult (result);
      unit_test_->listeners ()->repeater ()->OnTestPartResult (result);
    }
  DefaultPerThreadTestPartResultReporter::DefaultPerThreadTestPartResultReporter (UnitTestImpl * unit_test):unit_test_
      (unit_test)
    {
    }
    void DefaultPerThreadTestPartResultReporter::ReportTestPartResult (const
								       TestPartResult
								       &
								       result)
    {
      unit_test_->GetGlobalTestPartResultReporter ()->
	ReportTestPartResult (result);
    }
    TestPartResultReporterInterface
      * UnitTestImpl::GetGlobalTestPartResultReporter ()
    {
      internal::MutexLock lock (&global_test_part_result_reporter_mutex_);
      return global_test_part_result_repoter_;
    }
    void
      UnitTestImpl::SetGlobalTestPartResultReporter
      (TestPartResultReporterInterface * reporter)
    {
      internal::MutexLock lock (&global_test_part_result_reporter_mutex_);
      global_test_part_result_repoter_ = reporter;
    }
    TestPartResultReporterInterface
      * UnitTestImpl::GetTestPartResultReporterForCurrentThread ()
    {
      return per_thread_test_part_result_reporter_.get ();
    }
    void UnitTestImpl::SetTestPartResultReporterForCurrentThread
      (TestPartResultReporterInterface * reporter)
    {
      per_thread_test_part_result_reporter_.set (reporter);
    }
    int UnitTestImpl::successful_test_case_count () const
    {
      return CountIf (test_cases_, TestCasePassed);
    }
    int UnitTestImpl::failed_test_case_count () const
    {
      return CountIf (test_cases_, TestCaseFailed);
    }
    int UnitTestImpl::total_test_case_count () const
    {
      return static_cast < int >(test_cases_.size ());
    }
    int UnitTestImpl::test_case_to_run_count () const
    {
      return CountIf (test_cases_, ShouldRunTestCase);
    }
    int UnitTestImpl::successful_test_count () const
    {
      return SumOverTestCaseList (test_cases_,
				  &TestCase::successful_test_count);
    }
    int UnitTestImpl::failed_test_count () const
    {
      return SumOverTestCaseList (test_cases_, &TestCase::failed_test_count);
    }
    int UnitTestImpl::disabled_test_count () const
    {
      return SumOverTestCaseList (test_cases_,
				  &TestCase::disabled_test_count);
    }
    int UnitTestImpl::total_test_count () const
    {
      return SumOverTestCaseList (test_cases_, &TestCase::total_test_count);
    }
    int UnitTestImpl::test_to_run_count () const
    {
      return SumOverTestCaseList (test_cases_, &TestCase::test_to_run_count);
    }
    String UnitTestImpl::CurrentOsStackTraceExceptTop (int skip_count)
    {
      (void) skip_count;
      return String ("");
    }
    TimeInMillis GetTimeInMillis ()
    {
      struct timeval now;
      gettimeofday (&now, __null);
      return static_cast < TimeInMillis >
	(now.tv_sec) * 1000 + now.tv_usec / 1000;
    }
    String String::ShowCStringQuoted (const char *c_str)
    {
      return c_str ? String::Format ("\"%s\"", c_str) : String ("(null)");
    }
    static char *CloneString (const char *str, size_t length)
    {
      if (str == __null)
	{
	  return __null;
	}
      else
	{
	  char *const clone = new char[length + 1];
	  posix::StrNCpy (clone, str, length);
	  clone[length] = '\0';
	  return clone;
	}
    }
    const char *String::CloneCString (const char *c_str)
    {
      return (c_str == __null) ? __null : CloneString (c_str, strlen (c_str));
    }
    bool String::CStringEquals (const char *lhs, const char *rhs)
    {
      if (lhs == __null)
	return rhs == __null;
      if (rhs == __null)
	return false;
      return strcmp (lhs, rhs) == 0;
    }
    static void StreamWideCharsToMessage (const wchar_t * wstr, size_t length,
					  Message * msg)
    {
      for (size_t i = 0; i != length;)
	{
	  if (wstr[i] != L'\0')
	    {
	      *msg << WideStringToUtf8 (wstr + i,
					static_cast < int >(length - i));
	      while (i != length && wstr[i] != L'\0')
		i++;
	    }
	  else
	    {
	      *msg << '\0';
	      i++;
	    }
	}
    }
  }
  Message & Message::operator << (const::std::wstring & wstr)
  {
    internal::StreamWideCharsToMessage (wstr.c_str (), wstr.length (), this);
    return *this;
  }
AssertionResult::AssertionResult (const AssertionResult & other):success_ (other.success_),
    message_ (other.message_.get () != __null ?
	      new::std::string (*other.message_) :
	      static_cast <::std::string * >(__null))
  {
  }
  AssertionResult AssertionResult::operator! () const
  {
    AssertionResult negation (!success_);
    if (message_.get () != __null)
        negation << *message_;
      return negation;
  }
  AssertionResult AssertionSuccess ()
  {
    return AssertionResult (true);
  }
  AssertionResult AssertionFailure ()
  {
    return AssertionResult (false);
  }
  AssertionResult AssertionFailure (const Message & message)
  {
    return AssertionFailure () << message;
  }
  namespace internal
  {
    AssertionResult EqFailure (const char *expected_expression,
			       const char *actual_expression,
			       const String & expected_value,
			       const String & actual_value,
			       bool ignoring_case)
    {
      Message msg;
        msg << "Value of: " << actual_expression;
      if (actual_value != actual_expression)
	{
	  msg << "\n  Actual: " << actual_value;
	}
      msg << "\nExpected: " << expected_expression;
      if (ignoring_case)
	{
	  msg << " (ignoring case)";
	}
      if (expected_value != expected_expression)
	{
	  msg << "\nWhich is: " << expected_value;
	}
      return AssertionFailure () << msg;
    }
    String GetBoolAssertionFailureMessage (const AssertionResult &
					   assertion_result,
					   const char *expression_text,
					   const char *actual_predicate_value,
					   const char
					   *expected_predicate_value)
    {
      const char *actual_message = assertion_result.message ();
      Message msg;
      msg << "Value of: " << expression_text
	<< "\n  Actual: " << actual_predicate_value;
      if (actual_message[0] != '\0')
	msg << " (" << actual_message << ")";
      msg << "\nExpected: " << expected_predicate_value;
      return msg.GetString ();
    }
    AssertionResult DoubleNearPredFormat (const char *expr1,
					  const char *expr2,
					  const char *abs_error_expr,
					  double val1,
					  double val2, double abs_error)
    {
      const double diff = fabs (val1 - val2);
      if (diff <= abs_error)
	return AssertionSuccess ();
      return AssertionFailure ()
	<< "The difference between " << expr1 << " and " << expr2
	<< " is " << diff << ", which exceeds " << abs_error_expr <<
	", where\n" << expr1 << " evaluates to " << val1 << ",\n" << expr2 <<
	" evaluates to " << val2 << ", and\n" << abs_error_expr <<
	" evaluates to " << abs_error << ".";
    }
    template < typename RawType >
      AssertionResult FloatingPointLE (const char *expr1,
				       const char *expr2,
				       RawType val1, RawType val2)
    {
      if (val1 < val2)
	{
	  return AssertionSuccess ();
	}
      const FloatingPoint < RawType > lhs (val1), rhs (val2);
      if (lhs.AlmostEquals (rhs))
	{
	  return AssertionSuccess ();
	}
      ::std::stringstream val1_ss;
      val1_ss << std::setprecision (std::numeric_limits <
				    RawType >::digits10 + 2) << val1;
      ::std::stringstream val2_ss;
      val2_ss << std::setprecision (std::numeric_limits <
				    RawType >::digits10 + 2) << val2;
      return AssertionFailure () << "Expected: (" << expr1 << ") <= (" <<
	expr2 << ")\n" << "  Actual: " << StringStreamToString (&val1_ss) <<
	" vs " << StringStreamToString (&val2_ss);
    }
  }
  AssertionResult FloatLE (const char *expr1, const char *expr2,
			   float val1, float val2)
  {
    return internal::FloatingPointLE < float >(expr1, expr2, val1, val2);
  }
  AssertionResult DoubleLE (const char *expr1, const char *expr2,
			    double val1, double val2)
  {
    return internal::FloatingPointLE < double >(expr1, expr2, val1, val2);
  }
  namespace internal
  {
    AssertionResult CmpHelperEQ (const char *expected_expression,
				 const char *actual_expression,
				 BiggestInt expected, BiggestInt actual)
    {
      if (expected == actual)
	{
	  return AssertionSuccess ();
	}
      return EqFailure (expected_expression,
			actual_expression,
			FormatForComparisonFailureMessage (expected, actual),
			FormatForComparisonFailureMessage (actual, expected),
			false);
    }
    AssertionResult CmpHelperNE (const char *expr1, const char *expr2,
				 BiggestInt val1, BiggestInt val2)
    {
      if (val1 != val2)
	{
	  return AssertionSuccess ();
	}
      else
	{
	  return AssertionFailure () << "Expected: (" << expr1 << ") " "!="
	    " (" << expr2 << "), actual: " <<
	    FormatForComparisonFailureMessage (val1,
					       val2) << " vs " <<
	    FormatForComparisonFailureMessage (val2, val1);
	}
    }
    AssertionResult CmpHelperLE (const char *expr1, const char *expr2,
				 BiggestInt val1, BiggestInt val2)
    {
      if (val1 <= val2)
	{
	  return AssertionSuccess ();
	}
      else
	{
	  return AssertionFailure () << "Expected: (" << expr1 << ") " "<="
	    " (" << expr2 << "), actual: " <<
	    FormatForComparisonFailureMessage (val1,
					       val2) << " vs " <<
	    FormatForComparisonFailureMessage (val2, val1);
	}
    }
    AssertionResult CmpHelperLT (const char *expr1, const char *expr2,
				 BiggestInt val1, BiggestInt val2)
    {
      if (val1 < val2)
	{
	  return AssertionSuccess ();
	}
      else
	{
	  return AssertionFailure () << "Expected: (" << expr1 << ") " "<"
	    " (" << expr2 << "), actual: " <<
	    FormatForComparisonFailureMessage (val1,
					       val2) << " vs " <<
	    FormatForComparisonFailureMessage (val2, val1);
	}
    }
    AssertionResult CmpHelperGE (const char *expr1, const char *expr2,
				 BiggestInt val1, BiggestInt val2)
    {
      if (val1 >= val2)
	{
	  return AssertionSuccess ();
	}
      else
	{
	  return AssertionFailure () << "Expected: (" << expr1 << ") " ">="
	    " (" << expr2 << "), actual: " <<
	    FormatForComparisonFailureMessage (val1,
					       val2) << " vs " <<
	    FormatForComparisonFailureMessage (val2, val1);
	}
    }
    AssertionResult CmpHelperGT (const char *expr1, const char *expr2,
				 BiggestInt val1, BiggestInt val2)
    {
      if (val1 > val2)
	{
	  return AssertionSuccess ();
	}
      else
	{
	  return AssertionFailure () << "Expected: (" << expr1 << ") " ">"
	    " (" << expr2 << "), actual: " <<
	    FormatForComparisonFailureMessage (val1,
					       val2) << " vs " <<
	    FormatForComparisonFailureMessage (val2, val1);
	}
    }
    AssertionResult CmpHelperSTREQ (const char *expected_expression,
				    const char *actual_expression,
				    const char *expected, const char *actual)
    {
      if (String::CStringEquals (expected, actual))
	{
	  return AssertionSuccess ();
	}
      return EqFailure (expected_expression,
			actual_expression,
			String::ShowCStringQuoted (expected),
			String::ShowCStringQuoted (actual), false);
    }
    AssertionResult CmpHelperSTRCASEEQ (const char *expected_expression,
					const char *actual_expression,
					const char *expected,
					const char *actual)
    {
      if (String::CaseInsensitiveCStringEquals (expected, actual))
	{
	  return AssertionSuccess ();
	}
      return EqFailure (expected_expression,
			actual_expression,
			String::ShowCStringQuoted (expected),
			String::ShowCStringQuoted (actual), true);
    }
    AssertionResult CmpHelperSTRNE (const char *s1_expression,
				    const char *s2_expression,
				    const char *s1, const char *s2)
    {
      if (!String::CStringEquals (s1, s2))
	{
	  return AssertionSuccess ();
	}
      else
	{
	  return AssertionFailure () << "Expected: (" << s1_expression <<
	    ") != (" << s2_expression << "), actual: \"" << s1 << "\" vs \""
	    << s2 << "\"";
	}
    }
    AssertionResult CmpHelperSTRCASENE (const char *s1_expression,
					const char *s2_expression,
					const char *s1, const char *s2)
    {
      if (!String::CaseInsensitiveCStringEquals (s1, s2))
	{
	  return AssertionSuccess ();
	}
      else
	{
	  return AssertionFailure ()
	    << "Expected: (" << s1_expression << ") != ("
	    << s2_expression << ") (ignoring case), actual: \""
	    << s1 << "\" vs \"" << s2 << "\"";
	}
    }
  }
  namespace
  {
    bool IsSubstringPred (const char *needle, const char *haystack)
    {
      if (needle == __null || haystack == __null)
	return needle == haystack;
      return strstr (haystack, needle) != __null;
    }
    bool IsSubstringPred (const wchar_t * needle, const wchar_t * haystack)
    {
      if (needle == __null || haystack == __null)
	return needle == haystack;
      return wcsstr (haystack, needle) != __null;
    }
    template < typename StringType >
      bool IsSubstringPred (const StringType & needle,
			    const StringType & haystack)
    {
      return haystack.find (needle) != StringType::npos;
    }
    template < typename StringType >
      AssertionResult IsSubstringImpl (bool expected_to_be_substring,
				       const char *needle_expr,
				       const char *haystack_expr,
				       const StringType & needle,
				       const StringType & haystack)
    {
      if (IsSubstringPred (needle, haystack) == expected_to_be_substring)
	return AssertionSuccess ();
      const bool is_wide_string = sizeof (needle[0]) > 1;
      const char *const begin_string_quote = is_wide_string ? "L\"" : "\"";
      return AssertionFailure ()
	<< "Value of: " << needle_expr << "\n"
	<< "  Actual: " << begin_string_quote << needle << "\"\n"
	<< "Expected: " << (expected_to_be_substring ? "" : "not ")
	<< "a substring of " << haystack_expr << "\n"
	<< "Which is: " << begin_string_quote << haystack << "\"";
    }
  }
  AssertionResult IsSubstring (const char *needle_expr,
			       const char *haystack_expr, const char *needle,
			       const char *haystack)
  {
    return IsSubstringImpl (true, needle_expr, haystack_expr, needle,
			    haystack);
  }
  AssertionResult IsSubstring (const char *needle_expr,
			       const char *haystack_expr,
			       const wchar_t * needle,
			       const wchar_t * haystack)
  {
    return IsSubstringImpl (true, needle_expr, haystack_expr, needle,
			    haystack);
  }
  AssertionResult IsNotSubstring (const char *needle_expr,
				  const char *haystack_expr,
				  const char *needle, const char *haystack)
  {
    return IsSubstringImpl (false, needle_expr, haystack_expr, needle,
			    haystack);
  }
  AssertionResult IsNotSubstring (const char *needle_expr,
				  const char *haystack_expr,
				  const wchar_t * needle,
				  const wchar_t * haystack)
  {
    return IsSubstringImpl (false, needle_expr, haystack_expr, needle,
			    haystack);
  }
  AssertionResult IsSubstring (const char *needle_expr,
			       const char *haystack_expr,
			       const::std::string & needle,
			       const::std::string & haystack)
  {
    return IsSubstringImpl (true, needle_expr, haystack_expr, needle,
			    haystack);
  }
  AssertionResult IsNotSubstring (const char *needle_expr,
				  const char *haystack_expr,
				  const::std::string & needle,
				  const::std::string & haystack)
  {
    return IsSubstringImpl (false, needle_expr, haystack_expr, needle,
			    haystack);
  }
  AssertionResult IsSubstring (const char *needle_expr,
			       const char *haystack_expr,
			       const::std::wstring & needle,
			       const::std::wstring & haystack)
  {
    return IsSubstringImpl (true, needle_expr, haystack_expr, needle,
			    haystack);
  }
  AssertionResult IsNotSubstring (const char *needle_expr,
				  const char *haystack_expr,
				  const::std::wstring & needle,
				  const::std::wstring & haystack)
  {
    return IsSubstringImpl (false, needle_expr, haystack_expr, needle,
			    haystack);
  }
  namespace internal
  {
    const UInt32 kMaxCodePoint1 = (static_cast < UInt32 > (1) << 7) - 1;
    const UInt32 kMaxCodePoint2 = (static_cast < UInt32 > (1) << (5 + 6)) - 1;
    const UInt32 kMaxCodePoint3 =
      (static_cast < UInt32 > (1) << (4 + 2 * 6)) - 1;
    const UInt32 kMaxCodePoint4 =
      (static_cast < UInt32 > (1) << (3 + 3 * 6)) - 1;
    inline UInt32 ChopLowBits (UInt32 * bits, int n)
    {
      const UInt32 low_bits = *bits & ((static_cast < UInt32 > (1) << n) - 1);
       *bits >>= n;
        return low_bits;
    }
    char *CodePointToUtf8 (UInt32 code_point, char *str)
    {
      if (code_point <= kMaxCodePoint1)
	{
	  str[1] = '\0';
	  str[0] = static_cast < char >(code_point);
	}
      else if (code_point <= kMaxCodePoint2)
	{
	  str[2] = '\0';
	  str[1] = static_cast < char >(0x80 | ChopLowBits (&code_point, 6));
	  str[0] = static_cast < char >(0xC0 | code_point);
	}
      else if (code_point <= kMaxCodePoint3)
	{
	  str[3] = '\0';
	  str[2] = static_cast < char >(0x80 | ChopLowBits (&code_point, 6));
	  str[1] = static_cast < char >(0x80 | ChopLowBits (&code_point, 6));
	  str[0] = static_cast < char >(0xE0 | code_point);
	}
      else if (code_point <= kMaxCodePoint4)
	{
	  str[4] = '\0';
	  str[3] = static_cast < char >(0x80 | ChopLowBits (&code_point, 6));
	  str[2] = static_cast < char >(0x80 | ChopLowBits (&code_point, 6));
	  str[1] = static_cast < char >(0x80 | ChopLowBits (&code_point, 6));
	  str[0] = static_cast < char >(0xF0 | code_point);
	}
      else
	{
	  posix::StrNCpy (str,
			  String::Format ("(Invalid Unicode 0x%X)",
					  code_point).c_str (), 32);
	  str[31] = '\0';
	}
      return str;
    }
    inline bool IsUtf16SurrogatePair (wchar_t first, wchar_t second)
    {
      return sizeof (wchar_t) == 2 &&
	(first & 0xFC00) == 0xD800 && (second & 0xFC00) == 0xDC00;
    }
    inline UInt32 CreateCodePointFromUtf16SurrogatePair (wchar_t first,
							 wchar_t second)
    {
      const UInt32 mask = (1 << 10) - 1;
      return (sizeof (wchar_t) == 2) ?
	(((first & mask) << 10) | (second & mask)) + 0x10000 :
	static_cast < UInt32 > (first);
    }
    String WideStringToUtf8 (const wchar_t * str, int num_chars)
    {
      if (num_chars == -1)
	num_chars = static_cast < int >(wcslen (str));
      ::std::stringstream stream;
      for (int i = 0; i < num_chars; ++i)
	{
	  UInt32 unicode_code_point;
	  if (str[i] == L'\0')
	    {
	      break;
	    }
	  else if (i + 1 < num_chars
		   && IsUtf16SurrogatePair (str[i], str[i + 1]))
	    {
	      unicode_code_point =
		CreateCodePointFromUtf16SurrogatePair (str[i], str[i + 1]);
	      i++;
	    }
	  else
	    {
	      unicode_code_point = static_cast < UInt32 > (str[i]);
	    }
	  char buffer[32];
	  stream << CodePointToUtf8 (unicode_code_point, buffer);
	}
      return StringStreamToString (&stream);
    }
    String String::ShowWideCString (const wchar_t * wide_c_str)
    {
      if (wide_c_str == __null)
	return String ("(null)");
      return String (internal::WideStringToUtf8 (wide_c_str, -1).c_str ());
    }
    String String::ShowWideCStringQuoted (const wchar_t * wide_c_str)
    {
      if (wide_c_str == __null)
	return String ("(null)");
      return String::Format ("L\"%s\"",
			     String::ShowWideCString (wide_c_str).c_str ());
    }
    bool String::WideCStringEquals (const wchar_t * lhs, const wchar_t * rhs)
    {
      if (lhs == __null)
	return rhs == __null;
      if (rhs == __null)
	return false;
      return wcscmp (lhs, rhs) == 0;
    }
    AssertionResult CmpHelperSTREQ (const char *expected_expression,
				    const char *actual_expression,
				    const wchar_t * expected,
				    const wchar_t * actual)
    {
      if (String::WideCStringEquals (expected, actual))
	{
	  return AssertionSuccess ();
	}
      return EqFailure (expected_expression,
			actual_expression,
			String::ShowWideCStringQuoted (expected),
			String::ShowWideCStringQuoted (actual), false);
    }
    AssertionResult CmpHelperSTRNE (const char *s1_expression,
				    const char *s2_expression,
				    const wchar_t * s1, const wchar_t * s2)
    {
      if (!String::WideCStringEquals (s1, s2))
	{
	  return AssertionSuccess ();
	}
      return AssertionFailure () << "Expected: (" << s1_expression << ") != ("
	<< s2_expression << "), actual: "
	<< String::ShowWideCStringQuoted (s1)
	<< " vs " << String::ShowWideCStringQuoted (s2);
    }
    bool String::CaseInsensitiveCStringEquals (const char *lhs,
					       const char *rhs)
    {
      if (lhs == __null)
	return rhs == __null;
      if (rhs == __null)
	return false;
      return posix::StrCaseCmp (lhs, rhs) == 0;
    }
    bool String::CaseInsensitiveWideCStringEquals (const wchar_t * lhs,
						   const wchar_t * rhs)
    {
      if (lhs == __null)
	return rhs == __null;
      if (rhs == __null)
	return false;
      return wcscasecmp (lhs, rhs) == 0;
    }
    int String::Compare (const String & rhs) const
    {
      const char *const lhs_c_str = c_str ();
      const char *const rhs_c_str = rhs.c_str ();
      if (lhs_c_str == __null)
	{
	  return rhs_c_str == __null ? 0 : -1;
	}
      else if (rhs_c_str == __null)
	{
	  return 1;
	}
      const size_t shorter_str_len =
	length () <= rhs.length ()? length () : rhs.length ();
      for (size_t i = 0; i != shorter_str_len; i++)
	{
	  if (lhs_c_str[i] < rhs_c_str[i])
	    {
	      return -1;
	    }
	  else if (lhs_c_str[i] > rhs_c_str[i])
	    {
	      return 1;
	    }
	}
      return (length () < rhs.length ())? -1 :
	(length () > rhs.length ())? 1 : 0;
    }
    bool String::EndsWith (const char *suffix) const
    {
      if (suffix == __null || CStringEquals (suffix, ""))
	return true;
      if (c_str () == __null)
	return false;
      const size_t this_len = strlen (c_str ());
      const size_t suffix_len = strlen (suffix);
        return (this_len >= suffix_len) &&
	CStringEquals (c_str () + this_len - suffix_len, suffix);
    }
    bool String::EndsWithCaseInsensitive (const char *suffix) const
    {
      if (suffix == __null || CStringEquals (suffix, ""))
	return true;
      if (c_str () == __null)
	return false;
      const size_t this_len = strlen (c_str ());
      const size_t suffix_len = strlen (suffix);
        return (this_len >= suffix_len) &&
	CaseInsensitiveCStringEquals (c_str () + this_len - suffix_len,
				      suffix);
    }
    String String::Format (const char *format, ...)
    {
      va_list args;
      __builtin_va_start (args, format);
      char buffer[4096];
      const int kBufferSize = sizeof (buffer) / sizeof (buffer[0]);
      const int size = vsnprintf (buffer, kBufferSize, format, args);
      __builtin_va_end (args);
      if (size < 0 || size >= kBufferSize)
	{
	  return String ("<formatting error or buffer exceeded>");
	}
      else
	{
	  return String (buffer, size);
	}
    }
    String StringStreamToString (::std::stringstream * ss)
    {
      const::std::string & str = ss->str ();
      const char *const start = str.c_str ();
      const char *const end = start + str.length ();
      ::std::stringstream helper;
      for (const char *ch = start; ch != end; ++ch)
	{
	  if (*ch == '\0')
	    {
	      helper << "\\0";
	    }
	  else
	    {
	      helper.put (*ch);
	    }
	}
      return String (helper.str ().c_str ());
    }
    String AppendUserMessage (const String & gtest_msg,
			      const Message & user_msg)
    {
      const String user_msg_string = user_msg.GetString ();
      if (user_msg_string.empty ())
	{
	  return gtest_msg;
	}
      Message msg;
      msg << gtest_msg << "\n" << user_msg_string;
      return msg.GetString ();
    }
  }
TestResult::TestResult ():death_test_count_ (0), elapsed_time_ (0)
  {
  }
  TestResult::~TestResult ()
  {
  }
  const TestPartResult & TestResult::GetTestPartResult (int i) const
  {
    if (i < 0 || i >= total_part_count ())
      internal::posix::Abort ();
    return test_part_results_.at (i);
  }
  const TestProperty & TestResult::GetTestProperty (int i) const
  {
    if (i < 0 || i >= test_property_count ())
      internal::posix::Abort ();
    return test_properties_.at (i);
  }
  void TestResult::ClearTestPartResults ()
  {
    test_part_results_.clear ();
  }
  void TestResult::AddTestPartResult (const TestPartResult & test_part_result)
  {
    test_part_results_.push_back (test_part_result);
  }
  void TestResult::RecordProperty (const TestProperty & test_property)
  {
    if (!ValidateTestProperty (test_property))
      {
	return;
      }
    internal::MutexLock lock (&test_properites_mutex_);
    const std::vector < TestProperty >::iterator property_with_matching_key =
      std::find_if (test_properties_.begin (), test_properties_.end (),
		    internal::TestPropertyKeyIs (test_property.key ()));
    if (property_with_matching_key == test_properties_.end ())
      {
	test_properties_.push_back (test_property);
	return;
      }
    property_with_matching_key->SetValue (test_property.value ());
  }
  bool TestResult::ValidateTestProperty (const TestProperty & test_property)
  {
    internal::String key (test_property.key ());
    if (key == "name" || key == "status" || key == "time"
	|| key == "classname")
      {
	::testing::internal::AssertHelper (::testing::TestPartResult::
					   kNonFatalFailure, "gtest.cc", 1834,
					   "Failed") =::testing::
	  Message () << "Reserved key used in RecordProperty(): " << key <<
	  " ('name', 'status', 'time', and 'classname' are reserved by " <<
	  "Google Test" << ")";
	return false;
      }
    return true;
  }
  void TestResult::Clear ()
  {
    test_part_results_.clear ();
    test_properties_.clear ();
    death_test_count_ = 0;
    elapsed_time_ = 0;
  }
  bool TestResult::Failed () const
  {
    for (int i = 0; i < total_part_count (); ++i)
      {
	if (GetTestPartResult (i).failed ())
	  return true;
      }
    return false;
  }
  static bool TestPartFatallyFailed (const TestPartResult & result)
  {
    return result.fatally_failed ();
  }
  bool TestResult::HasFatalFailure () const
  {
    return CountIf (test_part_results_, TestPartFatallyFailed) > 0;
  }
  static bool TestPartNonfatallyFailed (const TestPartResult & result)
  {
    return result.nonfatally_failed ();
  }
  bool TestResult::HasNonfatalFailure () const
  {
    return CountIf (test_part_results_, TestPartNonfatallyFailed) > 0;
  }
  int TestResult::total_part_count () const
  {
    return static_cast < int >(test_part_results_.size ());
  }
  int TestResult::test_property_count () const
  {
    return static_cast < int >(test_properties_.size ());
  }
  Test::Test ():gtest_flag_saver_ (new internal::GTestFlagSaver)
  {
  }
  Test::~Test ()
  {
    delete gtest_flag_saver_;
  }
  void Test::SetUp ()
  {
  }
  void Test::TearDown ()
  {
  }
  void Test::RecordProperty (const char *key, const char *value)
  {
    UnitTest::GetInstance ()->RecordPropertyForCurrentTest (key, value);
  }
  void Test::RecordProperty (const char *key, int value)
  {
    Message value_message;
    value_message << value;
    RecordProperty (key, value_message.GetString ().c_str ());
  }
  namespace internal
  {
    void ReportFailureInUnknownLocation (TestPartResult::Type result_type,
					 const String & message)
    {
      UnitTest::GetInstance ()->AddTestPartResult (result_type,
						   __null,
						   -1, message, String ());
    }
  }
  bool Test::HasSameFixtureClass ()
  {
    internal::UnitTestImpl * const impl = internal::GetUnitTestImpl ();
    const TestCase *const test_case = impl->current_test_case ();
    const TestInfo *const first_test_info = test_case->test_info_list ()[0];
    const internal::TypeId first_fixture_id =
      first_test_info->fixture_class_id_;
    const char *const first_test_name = first_test_info->name ();
    const TestInfo *const this_test_info = impl->current_test_info ();
    const internal::TypeId this_fixture_id =
      this_test_info->fixture_class_id_;
    const char *const this_test_name = this_test_info->name ();
    if (this_fixture_id != first_fixture_id)
      {
	const bool first_is_TEST =
	  first_fixture_id == internal::GetTestTypeId ();
	const bool this_is_TEST =
	  this_fixture_id == internal::GetTestTypeId ();
	if (first_is_TEST || this_is_TEST)
	  {
	    const char *const TEST_name =
	      first_is_TEST ? first_test_name : this_test_name;
	    const char *const TEST_F_name =
	      first_is_TEST ? this_test_name : first_test_name;
	    ::testing::internal::AssertHelper (::testing::TestPartResult::
					       kNonFatalFailure, "gtest.cc",
					       1983,
					       "Failed") =::testing::
	      Message () <<
	      "All tests in the same test case must use the same test fixture\n"
	      << "class, so mixing TEST_F and TEST in the same test case is\n"
	      << "illegal.  In test case " << this_test_info->
	      test_case_name () << ",\n" << "test " << TEST_F_name <<
	      " is defined using TEST_F but\n" << "test " << TEST_name <<
	      " is defined using TEST.  You probably\n" <<
	      "want to change the TEST to TEST_F or move it to another test\n"
	      << "case.";
	  }
	else
	  {
	    ::testing::internal::AssertHelper (::testing::TestPartResult::
					       kNonFatalFailure, "gtest.cc",
					       1995,
					       "Failed") =::testing::
	      Message () <<
	      "All tests in the same test case must use the same test fixture\n"
	      << "class.  However, in test case " << this_test_info->
	      test_case_name () << ",\n" << "you defined test " <<
	      first_test_name << " and test " << this_test_name << "\n" <<
	      "using two different test fixture classes.  This can happen if\n"
	      <<
	      "the two classes are from different namespaces or translation\n"
	      <<
	      "units and have the same name.  You should probably rename one\n"
	      << "of the classes to put the tests into different test cases.";
	  }
	return false;
      }
    return true;
  }
  static internal::String FormatCxxExceptionMessage (const char *description,
						     const char *location)
  {
    Message message;
    if (description != __null)
      {
	message << "C++ exception with description \"" << description << "\"";
      }
    else
      {
	message << "Unknown C++ exception";
      }
    message << " thrown in " << location << ".";
    return message.GetString ();
  }
  static internal::String PrintTestPartResultToString (const TestPartResult &
						       test_part_result);
  class GoogleTestFailureException:public::std::runtime_error
  {
  public:
    explicit GoogleTestFailureException (const TestPartResult &
					 failure):::std::runtime_error
      (PrintTestPartResultToString (failure).c_str ())
    {
    }
  };
  namespace internal
  {
    template < class T, typename Result >
      Result HandleSehExceptionsInMethodIfSupported (T * object,
						     Result (T::*method) (),
						     const char *location)
    {
      (void) location;
      return (object->*method) ();
    }
    template < class T, typename Result >
      Result HandleExceptionsInMethodIfSupported (T * object,
						  Result (T::*method) (),
						  const char *location)
    {
      if (internal::GetUnitTestImpl ()->catch_exceptions ())
	{
	  try
	  {
	    return HandleSehExceptionsInMethodIfSupported (object, method,
							   location);
	  }
	  catch (const GoogleTestFailureException &)
	  {
	    throw;
	  } catch (const std::exception & e)
	  {
	    internal::ReportFailureInUnknownLocation (TestPartResult::
						      kFatalFailure,
						      FormatCxxExceptionMessage
						      (e.what (), location));
	  } catch (...)
	  {
	    internal::ReportFailureInUnknownLocation (TestPartResult::
						      kFatalFailure,
						      FormatCxxExceptionMessage
						      (__null, location));
	  }
	  return static_cast < Result > (0);
	}
      else
	{
	  return (object->*method) ();
	}
    }
  }
  void Test::Run ()
  {
    if (!HasSameFixtureClass ())
      return;
    internal::UnitTestImpl * const impl = internal::GetUnitTestImpl ();
    impl->os_stack_trace_getter ()->UponLeavingGTest ();
    internal::HandleExceptionsInMethodIfSupported (this, &Test::SetUp,
						   "SetUp()");
    if (!HasFatalFailure ())
      {
	impl->os_stack_trace_getter ()->UponLeavingGTest ();
	internal::HandleExceptionsInMethodIfSupported (this, &Test::TestBody,
						       "the test body");
      }
    impl->os_stack_trace_getter ()->UponLeavingGTest ();
    internal::HandleExceptionsInMethodIfSupported (this, &Test::TearDown,
						   "TearDown()");
  }
  bool Test::HasFatalFailure ()
  {
    return internal::GetUnitTestImpl ()->current_test_result ()->
      HasFatalFailure ();
  }
  bool Test::HasNonfatalFailure ()
  {
    return internal::GetUnitTestImpl ()->
      current_test_result ()->HasNonfatalFailure ();
  }
TestInfo::TestInfo (const char *a_test_case_name, const char *a_name, const char *a_type_param, const char *a_value_param, internal::TypeId fixture_class_id, internal::TestFactoryBase * factory):test_case_name_ (a_test_case_name),
    name_ (a_name),
    type_param_ (a_type_param ? new std::string (a_type_param) : __null),
    value_param_ (a_value_param ? new std::string (a_value_param) : __null),
    fixture_class_id_ (fixture_class_id),
    should_run_ (false),
    is_disabled_ (false),
    matches_filter_ (false), factory_ (factory), result_ ()
  {
  }
  TestInfo::~TestInfo ()
  {
    delete factory_;
  }
  namespace internal
  {
    TestInfo *MakeAndRegisterTestInfo (const char *test_case_name,
				       const char *name,
				       const char *type_param,
				       const char *value_param,
				       TypeId fixture_class_id,
				       SetUpTestCaseFunc set_up_tc,
				       TearDownTestCaseFunc tear_down_tc,
				       TestFactoryBase * factory)
    {
      TestInfo *const test_info =
	new TestInfo (test_case_name, name, type_param, value_param,
		      fixture_class_id, factory);
        GetUnitTestImpl ()->AddTestInfo (set_up_tc, tear_down_tc, test_info);
        return test_info;
    }
    void ReportInvalidTestCaseType (const char *test_case_name,
				    const char *file, int line)
    {
      Message errors;
      errors
	<< "Attempted redefinition of test case " << test_case_name << ".\n"
	<< "All tests in the same test case must use the same test fixture\n"
	<< "class.  However, in test case " << test_case_name <<
	", you tried\n" <<
	"to define a test using a fixture class different from the one\n" <<
	"used earlier. This can happen if the two fixture classes are\n" <<
	"from different namespaces and have the same name. You should\n" <<
	"probably rename one of the classes to put the tests into different\n"
	<< "test cases.";
      fprintf (stderr, "%s %s", FormatFileLocation (file, line).c_str (),
	       errors.GetString ().c_str ());
    }
  }
  namespace
  {
    class TestNameIs
    {
    public:
      explicit TestNameIs (const char *name):name_ (name)
      {
      }
      bool operator     () (const TestInfo * test_info) const
      {
	return test_info
	  && internal::String (test_info->name ()).Compare (name_) == 0;
      }
    private:
        internal::String name_;
    };
  }
  namespace internal
  {
    void UnitTestImpl::RegisterParameterizedTests ()
    {
      if (!parameterized_tests_registered_)
	{
	  parameterized_test_registry_.RegisterTests ();
	  parameterized_tests_registered_ = true;
	}
    }
  }
  void TestInfo::Run ()
  {
    if (!should_run_)
      return;
    internal::UnitTestImpl * const impl = internal::GetUnitTestImpl ();
    impl->set_current_test_info (this);
    TestEventListener *repeater =
      UnitTest::GetInstance ()->listeners ().repeater ();
    repeater->OnTestStart (*this);
    const TimeInMillis start = internal::GetTimeInMillis ();
    impl->os_stack_trace_getter ()->UponLeavingGTest ();
    Test *const test =
      internal::HandleExceptionsInMethodIfSupported (factory_,
						     &internal::
						     TestFactoryBase::
						     CreateTest,
						     "the test fixture's constructor");
    if ((test != __null) && !Test::HasFatalFailure ())
      {
	test->Run ();
      }
    impl->os_stack_trace_getter ()->UponLeavingGTest ();
    internal::HandleExceptionsInMethodIfSupported (test, &Test::DeleteSelf_,
						   "the test fixture's destructor");
    result_.set_elapsed_time (internal::GetTimeInMillis () - start);
    repeater->OnTestEnd (*this);
    impl->set_current_test_info (__null);
  }
  int TestCase::successful_test_count () const
  {
    return CountIf (test_info_list_, TestPassed);
  }
  int TestCase::failed_test_count () const
  {
    return CountIf (test_info_list_, TestFailed);
  }
  int TestCase::disabled_test_count () const
  {
    return CountIf (test_info_list_, TestDisabled);
  }
  int TestCase::test_to_run_count () const
  {
    return CountIf (test_info_list_, ShouldRunTest);
  }
  int TestCase::total_test_count () const
  {
    return static_cast < int >(test_info_list_.size ());
  }
  TestCase::TestCase (const char *a_name, const char *a_type_param,
		      Test::SetUpTestCaseFunc set_up_tc,
		      Test::TearDownTestCaseFunc tear_down_tc):name_ (a_name),
    type_param_ (a_type_param ? new std::string (a_type_param) : __null),
    set_up_tc_ (set_up_tc),
    tear_down_tc_ (tear_down_tc), should_run_ (false), elapsed_time_ (0)
  {
  }
  TestCase::~TestCase ()
  {
    ForEach (test_info_list_, internal::Delete < TestInfo >);
  }
  const TestInfo *TestCase::GetTestInfo (int i) const
  {
    const int index = GetElementOr (test_indices_, i, -1);
      return index < 0 ? __null : test_info_list_[index];
  }
  TestInfo *TestCase::GetMutableTestInfo (int i)
  {
    const int index = GetElementOr (test_indices_, i, -1);
    return index < 0 ? __null : test_info_list_[index];
  }
  void TestCase::AddTestInfo (TestInfo * test_info)
  {
    test_info_list_.push_back (test_info);
    test_indices_.push_back (static_cast < int >(test_indices_.size ()));
  }
  void TestCase::Run ()
  {
    if (!should_run_)
      return;
    internal::UnitTestImpl * const impl = internal::GetUnitTestImpl ();
    impl->set_current_test_case (this);
    TestEventListener *repeater =
      UnitTest::GetInstance ()->listeners ().repeater ();
    repeater->OnTestCaseStart (*this);
    impl->os_stack_trace_getter ()->UponLeavingGTest ();
    internal::HandleExceptionsInMethodIfSupported (this,
						   &TestCase::
						   RunSetUpTestCase,
						   "SetUpTestCase()");
    const internal::TimeInMillis start = internal::GetTimeInMillis ();
    for (int i = 0; i < total_test_count (); i++)
      {
	GetMutableTestInfo (i)->Run ();
      }
    elapsed_time_ = internal::GetTimeInMillis () - start;
    impl->os_stack_trace_getter ()->UponLeavingGTest ();
    internal::HandleExceptionsInMethodIfSupported (this,
						   &TestCase::
						   RunTearDownTestCase,
						   "TearDownTestCase()");
    repeater->OnTestCaseEnd (*this);
    impl->set_current_test_case (__null);
  }
  void TestCase::ClearResult ()
  {
    ForEach (test_info_list_, TestInfo::ClearTestResult);
  }
  void TestCase::ShuffleTests (internal::Random * random)
  {
    Shuffle (random, &test_indices_);
  }
  void TestCase::UnshuffleTests ()
  {
    for (size_t i = 0; i < test_indices_.size (); i++)
      {
	test_indices_[i] = static_cast < int >(i);
      }
  }
  static internal::String FormatCountableNoun (int count,
					       const char *singular_form,
					       const char *plural_form)
  {
    return internal::String::Format ("%d %s", count,
				     count ==
				     1 ? singular_form : plural_form);
  }
  static internal::String FormatTestCount (int test_count)
  {
    return FormatCountableNoun (test_count, "test", "tests");
  }
  static internal::String FormatTestCaseCount (int test_case_count)
  {
    return FormatCountableNoun (test_case_count, "test case", "test cases");
  }
  static const char *TestPartResultTypeToString (TestPartResult::Type type)
  {
    switch (type)
      {
      case TestPartResult::kSuccess:
	return "Success";
      case TestPartResult::kNonFatalFailure:
      case TestPartResult::kFatalFailure:
	return "Failure\n";
      default:
	return "Unknown result type";
      }
  }
  static internal::String PrintTestPartResultToString (const TestPartResult &
						       test_part_result)
  {
    return (Message ()
	    << internal::FormatFileLocation (test_part_result.file_name (),
					     test_part_result.line_number ())
	    << " " << TestPartResultTypeToString (test_part_result.type ())
	    << test_part_result.message ()).GetString ();
  }
  static void PrintTestPartResult (const TestPartResult & test_part_result)
  {
    const internal::String & result =
      PrintTestPartResultToString (test_part_result);
    printf ("%s\n", result.c_str ());
    fflush (stdout);
  }
  namespace internal
  {
    enum GTestColor
    {
      COLOR_DEFAULT,
      COLOR_RED,
      COLOR_GREEN,
      COLOR_YELLOW
    };
    const char *GetAnsiColorCode (GTestColor color)
    {
      switch (color)
	{
	case COLOR_RED:
	  return "1";
	  case COLOR_GREEN:return "2";
	  case COLOR_YELLOW:return "3";
	  default:return __null;
	};
    }
    bool ShouldUseColor (bool stdout_is_tty)
    {
      const char *const gtest_color = FLAGS_gtest_color.c_str ();
      if (String::CaseInsensitiveCStringEquals (gtest_color, "auto"))
	{
	  const char *const term = posix::GetEnv ("TERM");
	  const bool term_supports_color =
	    String::CStringEquals (term, "xterm") ||
	    String::CStringEquals (term, "xterm-color") ||
	    String::CStringEquals (term, "xterm-256color") ||
	    String::CStringEquals (term, "screen") ||
	    String::CStringEquals (term, "linux") ||
	    String::CStringEquals (term, "cygwin");
	  return stdout_is_tty && term_supports_color;
	}
      return String::CaseInsensitiveCStringEquals (gtest_color, "yes") ||
	String::CaseInsensitiveCStringEquals (gtest_color, "true") ||
	String::CaseInsensitiveCStringEquals (gtest_color, "t") ||
	String::CStringEquals (gtest_color, "1");
    }
    void ColoredPrintf (GTestColor color, const char *fmt, ...)
    {
      va_list args;
      __builtin_va_start (args, fmt);
      static const bool in_color_mode =
	ShouldUseColor (posix::IsATTY (posix::FileNo (stdout)) != 0);
      const bool use_color = in_color_mode && (color != COLOR_DEFAULT);
      if (!use_color)
	{
	  vprintf (fmt, args);
	  __builtin_va_end (args);
	  return;
	}
      printf ("\033[0;3%sm", GetAnsiColorCode (color));
      vprintf (fmt, args);
      printf ("\033[m");
      __builtin_va_end (args);
    }
    void PrintFullTestCommentIfPresent (const TestInfo & test_info)
    {
      const char *const type_param = test_info.type_param ();
      const char *const value_param = test_info.value_param ();
      if (type_param != __null || value_param != __null)
	{
	  printf (", where ");
	  if (type_param != __null)
	    {
	      printf ("TypeParam = %s", type_param);
	      if (value_param != __null)
		printf (" and ");
	    }
	  if (value_param != __null)
	    {
	      printf ("GetParam() = %s", value_param);
	    }
	}
    }
    class PrettyUnitTestResultPrinter:public TestEventListener
    {
    public:
      PrettyUnitTestResultPrinter ()
      {
      }
      static void PrintTestName (const char *test_case, const char *test)
      {
	printf ("%s.%s", test_case, test);
      }
      virtual void OnTestProgramStart (const UnitTest &)
      {
      }
      virtual void OnTestIterationStart (const UnitTest & unit_test,
					 int iteration);
      virtual void OnEnvironmentsSetUpStart (const UnitTest & unit_test);
      virtual void OnEnvironmentsSetUpEnd (const UnitTest &)
      {
      }
      virtual void OnTestCaseStart (const TestCase & test_case);
      virtual void OnTestStart (const TestInfo & test_info);
      virtual void OnTestPartResult (const TestPartResult & result);
      virtual void OnTestEnd (const TestInfo & test_info);
      virtual void OnTestCaseEnd (const TestCase & test_case);
      virtual void OnEnvironmentsTearDownStart (const UnitTest & unit_test);
      virtual void OnEnvironmentsTearDownEnd (const UnitTest &)
      {
      }
      virtual void OnTestIterationEnd (const UnitTest & unit_test,
				       int iteration);
      virtual void OnTestProgramEnd (const UnitTest &)
      {
      }
    private:
      static void PrintFailedTests (const UnitTest & unit_test);
      internal::String test_case_name_;
    };
    void PrettyUnitTestResultPrinter::OnTestIterationStart (const UnitTest &
							    unit_test,
							    int iteration)
    {
      if (FLAGS_gtest_repeat != 1)
	printf ("\nRepeating all tests (iteration %d) . . .\n\n",
		iteration + 1);
      const char *const filter = FLAGS_gtest_filter.c_str ();
      if (!internal::String::CStringEquals (filter, kUniversalFilter))
	{
	  ColoredPrintf (COLOR_YELLOW,
			 "Note: %s filter = %s\n", "Google Test", filter);
	}
      if (internal::ShouldShard (kTestTotalShards, kTestShardIndex, false))
	{
	  const Int32 shard_index = Int32FromEnvOrDie (kTestShardIndex, -1);
	  ColoredPrintf (COLOR_YELLOW,
			 "Note: This is test shard %d of %s.\n",
			 static_cast < int >(shard_index) + 1,
			 internal::posix::GetEnv (kTestTotalShards));
	}
      if (FLAGS_gtest_shuffle)
	{
	  ColoredPrintf (COLOR_YELLOW,
			 "Note: Randomizing tests' orders with a seed of %d .\n",
			 unit_test.random_seed ());
	}
      ColoredPrintf (COLOR_GREEN, "[==========] ");
      printf ("Running %s from %s.\n",
	      FormatTestCount (unit_test.test_to_run_count ()).c_str (),
	      FormatTestCaseCount (unit_test.test_case_to_run_count ()).
	      c_str ());
      fflush (stdout);
    }
    void PrettyUnitTestResultPrinter::OnEnvironmentsSetUpStart (const UnitTest
								&)
    {
      ColoredPrintf (COLOR_GREEN, "[----------] ");
      printf ("Global test environment set-up.\n");
      fflush (stdout);
    }
    void PrettyUnitTestResultPrinter::OnTestCaseStart (const TestCase &
						       test_case)
    {
      test_case_name_ = test_case.name ();
      const internal::String counts =
	FormatCountableNoun (test_case.test_to_run_count (), "test", "tests");
      ColoredPrintf (COLOR_GREEN, "[----------] ");
      printf ("%s from %s", counts.c_str (), test_case_name_.c_str ());
      if (test_case.type_param () == __null)
	{
	  printf ("\n");
	}
      else
	{
	  printf (", where TypeParam = %s\n", test_case.type_param ());
	}
      fflush (stdout);
    }
    void PrettyUnitTestResultPrinter::OnTestStart (const TestInfo & test_info)
    {
      ColoredPrintf (COLOR_GREEN, "[ RUN      ] ");
      PrintTestName (test_case_name_.c_str (), test_info.name ());
      printf ("\n");
      fflush (stdout);
    }
    void PrettyUnitTestResultPrinter::OnTestPartResult (const TestPartResult &
							result)
    {
      if (result.type () == TestPartResult::kSuccess)
	return;
      PrintTestPartResult (result);
      fflush (stdout);
    }
    void PrettyUnitTestResultPrinter::OnTestEnd (const TestInfo & test_info)
    {
      if (test_info.result ()->Passed ())
	{
	  ColoredPrintf (COLOR_GREEN, "[       OK ] ");
	}
      else
	{
	  ColoredPrintf (COLOR_RED, "[  FAILED  ] ");
	}
      PrintTestName (test_case_name_.c_str (), test_info.name ());
      if (test_info.result ()->Failed ())
	PrintFullTestCommentIfPresent (test_info);
      if (FLAGS_gtest_print_time)
	{
	  printf (" (%s ms)\n",
		  internal::StreamableToString (test_info.result ()->
						elapsed_time ()).c_str ());
	}
      else
	{
	  printf ("\n");
	}
      fflush (stdout);
    }
    void PrettyUnitTestResultPrinter::OnTestCaseEnd (const TestCase &
						     test_case)
    {
      if (!FLAGS_gtest_print_time)
	return;
      test_case_name_ = test_case.name ();
      const internal::String counts =
	FormatCountableNoun (test_case.test_to_run_count (), "test", "tests");
      ColoredPrintf (COLOR_GREEN, "[----------] ");
      printf ("%s from %s (%s ms total)\n\n",
	      counts.c_str (), test_case_name_.c_str (),
	      internal::StreamableToString (test_case.elapsed_time ()).
	      c_str ());
      fflush (stdout);
    }
    void PrettyUnitTestResultPrinter::OnEnvironmentsTearDownStart (const
								   UnitTest &)
    {
      ColoredPrintf (COLOR_GREEN, "[----------] ");
      printf ("Global test environment tear-down\n");
      fflush (stdout);
    }
    void PrettyUnitTestResultPrinter::PrintFailedTests (const UnitTest &
							unit_test)
    {
      const int failed_test_count = unit_test.failed_test_count ();
      if (failed_test_count == 0)
	{
	  return;
	}
      for (int i = 0; i < unit_test.total_test_case_count (); ++i)
	{
	  const TestCase & test_case = *unit_test.GetTestCase (i);
	  if (!test_case.should_run ()
	      || (test_case.failed_test_count () == 0))
	    {
	      continue;
	    }
	  for (int j = 0; j < test_case.total_test_count (); ++j)
	    {
	      const TestInfo & test_info = *test_case.GetTestInfo (j);
	      if (!test_info.should_run () || test_info.result ()->Passed ())
		{
		  continue;
		}
	      ColoredPrintf (COLOR_RED, "[  FAILED  ] ");
	      printf ("%s.%s", test_case.name (), test_info.name ());
	      PrintFullTestCommentIfPresent (test_info);
	      printf ("\n");
	    }
	}
    }
    void PrettyUnitTestResultPrinter::OnTestIterationEnd (const UnitTest &
							  unit_test, int)
    {
      ColoredPrintf (COLOR_GREEN, "[==========] ");
      printf ("%s from %s ran.",
	      FormatTestCount (unit_test.test_to_run_count ()).c_str (),
	      FormatTestCaseCount (unit_test.test_case_to_run_count ()).
	      c_str ());
      if (FLAGS_gtest_print_time)
	{
	  printf (" (%s ms total)",
		  internal::StreamableToString (unit_test.elapsed_time ()).
		  c_str ());
	}
      printf ("\n");
      ColoredPrintf (COLOR_GREEN, "[  PASSED  ] ");
      printf ("%s.\n",
	      FormatTestCount (unit_test.successful_test_count ()).c_str ());
      int num_failures = unit_test.failed_test_count ();
      if (!unit_test.Passed ())
	{
	  const int failed_test_count = unit_test.failed_test_count ();
	  ColoredPrintf (COLOR_RED, "[  FAILED  ] ");
	  printf ("%s, listed below:\n",
		  FormatTestCount (failed_test_count).c_str ());
	  PrintFailedTests (unit_test);
	  printf ("\n%2d FAILED %s\n", num_failures,
		  num_failures == 1 ? "TEST" : "TESTS");
	}
      int num_disabled = unit_test.disabled_test_count ();
      if (num_disabled && !FLAGS_gtest_also_run_disabled_tests)
	{
	  if (!num_failures)
	    {
	      printf ("\n");
	    }
	  ColoredPrintf (COLOR_YELLOW,
			 "  YOU HAVE %d DISABLED %s\n\n",
			 num_disabled, num_disabled == 1 ? "TEST" : "TESTS");
	}
      fflush (stdout);
    }
    class TestEventRepeater:public TestEventListener
    {
    public:
      TestEventRepeater ():forwarding_enabled_ (true)
      {
      }
      virtual ~ TestEventRepeater ();
      void Append (TestEventListener * listener);
      TestEventListener *Release (TestEventListener * listener);
      bool forwarding_enabled () const
      {
	return forwarding_enabled_;
      }
      void set_forwarding_enabled (bool enable)
      {
	forwarding_enabled_ = enable;
      }
      virtual void OnTestProgramStart (const UnitTest & unit_test);
      virtual void OnTestIterationStart (const UnitTest & unit_test,
					 int iteration);
      virtual void OnEnvironmentsSetUpStart (const UnitTest & unit_test);
      virtual void OnEnvironmentsSetUpEnd (const UnitTest & unit_test);
      virtual void OnTestCaseStart (const TestCase & test_case);
      virtual void OnTestStart (const TestInfo & test_info);
      virtual void OnTestPartResult (const TestPartResult & result);
      virtual void OnTestEnd (const TestInfo & test_info);
      virtual void OnTestCaseEnd (const TestCase & test_case);
      virtual void OnEnvironmentsTearDownStart (const UnitTest & unit_test);
      virtual void OnEnvironmentsTearDownEnd (const UnitTest & unit_test);
      virtual void OnTestIterationEnd (const UnitTest & unit_test,
				       int iteration);
      virtual void OnTestProgramEnd (const UnitTest & unit_test);
    private:
      bool forwarding_enabled_;
      std::vector < TestEventListener * >listeners_;
      TestEventRepeater (TestEventRepeater const &);
      void operator= (TestEventRepeater const &);
    };
    TestEventRepeater::~TestEventRepeater ()
    {
      ForEach (listeners_, Delete < TestEventListener >);
    }
    void TestEventRepeater::Append (TestEventListener * listener)
    {
      listeners_.push_back (listener);
    }
    TestEventListener *TestEventRepeater::Release (TestEventListener *
						   listener)
    {
      for (size_t i = 0; i < listeners_.size (); ++i)
	{
	  if (listeners_[i] == listener)
	    {
	      listeners_.erase (listeners_.begin () + i);
	      return listener;
	    }
	}
      return __null;
    }
    void TestEventRepeater::OnTestProgramStart (const UnitTest & parameter)
    {
      if (forwarding_enabled_)
	{
	  for (size_t i = 0; i < listeners_.size (); i++)
	    {
	      listeners_[i]->OnTestProgramStart (parameter);
	    }
	}
    }
    void TestEventRepeater::OnEnvironmentsSetUpStart (const UnitTest &
						      parameter)
    {
      if (forwarding_enabled_)
	{
	  for (size_t i = 0; i < listeners_.size (); i++)
	    {
	      listeners_[i]->OnEnvironmentsSetUpStart (parameter);
	    }
	}
    }
    void TestEventRepeater::OnTestCaseStart (const TestCase & parameter)
    {
      if (forwarding_enabled_)
	{
	  for (size_t i = 0; i < listeners_.size (); i++)
	    {
	      listeners_[i]->OnTestCaseStart (parameter);
	    }
	}
    }
    void TestEventRepeater::OnTestStart (const TestInfo & parameter)
    {
      if (forwarding_enabled_)
	{
	  for (size_t i = 0; i < listeners_.size (); i++)
	    {
	      listeners_[i]->OnTestStart (parameter);
	    }
	}
    }
    void TestEventRepeater::OnTestPartResult (const TestPartResult &
					      parameter)
    {
      if (forwarding_enabled_)
	{
	  for (size_t i = 0; i < listeners_.size (); i++)
	    {
	      listeners_[i]->OnTestPartResult (parameter);
	    }
	}
    }
    void TestEventRepeater::OnEnvironmentsTearDownStart (const UnitTest &
							 parameter)
    {
      if (forwarding_enabled_)
	{
	  for (size_t i = 0; i < listeners_.size (); i++)
	    {
	      listeners_[i]->OnEnvironmentsTearDownStart (parameter);
	    }
	}
    }
    void TestEventRepeater::OnEnvironmentsSetUpEnd (const UnitTest &
						    parameter)
    {
      if (forwarding_enabled_)
	{
	  for (int i = static_cast < int >(listeners_.size ()) - 1; i >= 0;
	       i--)
	    {
	      listeners_[i]->OnEnvironmentsSetUpEnd (parameter);
	}}
    }
    void TestEventRepeater::OnEnvironmentsTearDownEnd (const UnitTest &
						       parameter)
    {
      if (forwarding_enabled_)
	{
	  for (int i = static_cast < int >(listeners_.size ()) - 1; i >= 0;
	       i--)
	    {
	      listeners_[i]->OnEnvironmentsTearDownEnd (parameter);
	}}
    }
    void TestEventRepeater::OnTestEnd (const TestInfo & parameter)
    {
      if (forwarding_enabled_)
	{
	  for (int i = static_cast < int >(listeners_.size ()) - 1; i >= 0;
	       i--)
	    {
	      listeners_[i]->OnTestEnd (parameter);
	}}
    }
    void TestEventRepeater::OnTestCaseEnd (const TestCase & parameter)
    {
      if (forwarding_enabled_)
	{
	  for (int i = static_cast < int >(listeners_.size ()) - 1; i >= 0;
	       i--)
	    {
	      listeners_[i]->OnTestCaseEnd (parameter);
	}}
    }
    void TestEventRepeater::OnTestProgramEnd (const UnitTest & parameter)
    {
      if (forwarding_enabled_)
	{
	  for (int i = static_cast < int >(listeners_.size ()) - 1; i >= 0;
	       i--)
	    {
	      listeners_[i]->OnTestProgramEnd (parameter);
	}}
    }
    void TestEventRepeater::OnTestIterationStart (const UnitTest & unit_test,
						  int iteration)
    {
      if (forwarding_enabled_)
	{
	  for (size_t i = 0; i < listeners_.size (); i++)
	    {
	      listeners_[i]->OnTestIterationStart (unit_test, iteration);
	    }
	}
    }
    void TestEventRepeater::OnTestIterationEnd (const UnitTest & unit_test,
						int iteration)
    {
      if (forwarding_enabled_)
	{
	  for (int i = static_cast < int >(listeners_.size ()) - 1; i >= 0;
	       i--)
	    {
	      listeners_[i]->OnTestIterationEnd (unit_test, iteration);
	    }
	}
    }
    class XmlUnitTestResultPrinter:public EmptyTestEventListener
    {
    public:
      explicit XmlUnitTestResultPrinter (const char *output_file);
      virtual void OnTestIterationEnd (const UnitTest & unit_test,
				       int iteration);
    private:
      static bool IsNormalizableWhitespace (char c)
      {
	return c == 0x9 || c == 0xA || c == 0xD;
      }
      static bool IsValidXmlCharacter (char c)
      {
	return IsNormalizableWhitespace (c) || c >= 0x20;
      }
      static String EscapeXml (const char *str, bool is_attribute);
      static string RemoveInvalidXmlCharacters (const string & str);
      static String EscapeXmlAttribute (const char *str)
      {
	return EscapeXml (str, true);
      }
      static String EscapeXmlText (const char *str)
      {
	return EscapeXml (str, false);
      }
      static void OutputXmlCDataSection (::std::ostream * stream,
					 const char *data);
      static void OutputXmlTestInfo (::std::ostream * stream,
				     const char *test_case_name,
				     const TestInfo & test_info);
      static void PrintXmlTestCase (FILE * out, const TestCase & test_case);
      static void PrintXmlUnitTest (FILE * out, const UnitTest & unit_test);
      static String TestPropertiesAsXmlAttributes (const TestResult & result);
      const String output_file_;
      XmlUnitTestResultPrinter (XmlUnitTestResultPrinter const &);
      void operator= (XmlUnitTestResultPrinter const &);
    };
    XmlUnitTestResultPrinter::XmlUnitTestResultPrinter (const char
							*output_file):output_file_
      (output_file)
    {
      if (output_file_.c_str () == __null || output_file_.empty ())
	{
	  fprintf (stderr, "XML output file may not be null\n");
	  fflush (stderr);
	  exit (1);
	}
    }
    void XmlUnitTestResultPrinter::OnTestIterationEnd (const UnitTest &
						       unit_test, int)
    {
      FILE *xmlout = __null;
      FilePath output_file (output_file_);
      FilePath output_dir (output_file.RemoveFileName ());
      if (output_dir.CreateDirectoriesRecursively ())
	{
	  xmlout = posix::FOpen (output_file_.c_str (), "w");
	}
      if (xmlout == __null)
	{
	  fprintf (stderr,
		   "Unable to open file \"%s\"\n", output_file_.c_str ());
	  fflush (stderr);
	  exit (1);
	}
      PrintXmlUnitTest (xmlout, unit_test);
      fclose (xmlout);
    }
    String XmlUnitTestResultPrinter::EscapeXml (const char *str,
						bool is_attribute)
    {
      Message m;
      if (str != __null)
	{
	  for (const char *src = str; *src; ++src)
	    {
	      switch (*src)
		{
		case '<':
		  m << "&lt;";
		  break;
		case '>':
		  m << "&gt;";
		  break;
		case '&':
		  m << "&amp;";
		  break;
		case '\'':
		  if (is_attribute)
		    m << "&apos;";
		  else
		    m << '\'';
		  break;
		case '"':
		  if (is_attribute)
		    m << "&quot;";
		  else
		    m << '"';
		  break;
		default:
		  if (IsValidXmlCharacter (*src))
		    {
		      if (is_attribute && IsNormalizableWhitespace (*src))
			;
		      else
			m << *src;
		    }
		  break;
		}
	    }
	}
      return m.GetString ();
    }
    string XmlUnitTestResultPrinter::RemoveInvalidXmlCharacters (const string
								 & str)
    {
      string output;
      output.reserve (str.size ());
      for (string::const_iterator it = str.begin (); it != str.end (); ++it)
	if (IsValidXmlCharacter (*it))
	  output.push_back (*it);
      return output;
    }
    std::string FormatTimeInMillisAsSeconds (TimeInMillis ms)
    {
      ::std::stringstream ss;
      ss << ms / 1000.0;
      return ss.str ();
    }
    void XmlUnitTestResultPrinter::OutputXmlCDataSection (::std::ostream *
							  stream,
							  const char *data)
    {
      const char *segment = data;
      *stream << "<![CDATA[";
      for (;;)
	{
	  const char *const next_segment = strstr (segment, "]]>");
	  if (next_segment != __null)
	    {
	      stream->write (segment,
			     static_cast < std::streamsize >
			     (next_segment - segment));
	      *stream << "]]>]]&gt;<![CDATA[";
	      segment = next_segment + strlen ("]]>");
	    }
	  else
	    {
	      *stream << segment;
	      break;
	    }
	}
      *stream << "]]>";
    }
    void XmlUnitTestResultPrinter::OutputXmlTestInfo (::std::ostream * stream,
						      const char
						      *test_case_name,
						      const TestInfo &
						      test_info)
    {
      const TestResult & result = *test_info.result ();
      *stream << "    <testcase name=\""
	<< EscapeXmlAttribute (test_info.name ()).c_str () << "\"";
      if (test_info.value_param () != __null)
	{
	  *stream << " value_param=\"" <<
	    EscapeXmlAttribute (test_info.value_param ()) << "\"";
	}
      if (test_info.type_param () != __null)
	{
	  *stream << " type_param=\"" <<
	    EscapeXmlAttribute (test_info.type_param ()) << "\"";
	}
      *stream << " status=\""
	<< (test_info.should_run ()? "run" : "notrun")
	<< "\" time=\""
	<< FormatTimeInMillisAsSeconds (result.elapsed_time ())
	<< "\" classname=\"" << EscapeXmlAttribute (test_case_name).c_str ()
	<< "\"" << TestPropertiesAsXmlAttributes (result).c_str ();
      int failures = 0;
      for (int i = 0; i < result.total_part_count (); ++i)
	{
	  const TestPartResult & part = result.GetTestPartResult (i);
	  if (part.failed ())
	    {
	      if (++failures == 1)
		*stream << ">\n";
	      *stream << "      <failure message=\""
		<< EscapeXmlAttribute (part.summary ()).c_str ()
		<< "\" type=\"\">";
	      const string location =
		internal::FormatCompilerIndependentFileLocation (part.
								 file_name (),
								 part.
								 line_number
								 ());
	      const string message = location + "\n" + part.message ();
	      OutputXmlCDataSection (stream,
				     RemoveInvalidXmlCharacters
				     (message).c_str ());
	      *stream << "</failure>\n";
	    }
	}
      if (failures == 0)
	*stream << " />\n";
      else
	*stream << "    </testcase>\n";
    }
    void XmlUnitTestResultPrinter::PrintXmlTestCase (FILE * out,
						     const TestCase &
						     test_case)
    {
      fprintf (out,
	       "  <testsuite name=\"%s\" tests=\"%d\" failures=\"%d\" "
	       "disabled=\"%d\" ",
	       EscapeXmlAttribute (test_case.name ()).c_str (),
	       test_case.total_test_count (),
	       test_case.failed_test_count (),
	       test_case.disabled_test_count ());
      fprintf (out,
	       "errors=\"0\" time=\"%s\">\n",
	       FormatTimeInMillisAsSeconds (test_case.elapsed_time ()).
	       c_str ());
      for (int i = 0; i < test_case.total_test_count (); ++i)
	{
	  ::std::stringstream stream;
	  OutputXmlTestInfo (&stream, test_case.name (),
			     *test_case.GetTestInfo (i));
	  fprintf (out, "%s", StringStreamToString (&stream).c_str ());
	}
      fprintf (out, "  </testsuite>\n");
    }
    void XmlUnitTestResultPrinter::PrintXmlUnitTest (FILE * out,
						     const UnitTest &
						     unit_test)
    {
      fprintf (out, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
      fprintf (out,
	       "<testsuites tests=\"%d\" failures=\"%d\" disabled=\"%d\" "
	       "errors=\"0\" time=\"%s\" ",
	       unit_test.total_test_count (),
	       unit_test.failed_test_count (),
	       unit_test.disabled_test_count (),
	       FormatTimeInMillisAsSeconds (unit_test.elapsed_time ()).
	       c_str ());
      if (FLAGS_gtest_shuffle)
	{
	  fprintf (out, "random_seed=\"%d\" ", unit_test.random_seed ());
	}
      fprintf (out, "name=\"AllTests\">\n");
      for (int i = 0; i < unit_test.total_test_case_count (); ++i)
	PrintXmlTestCase (out, *unit_test.GetTestCase (i));
      fprintf (out, "</testsuites>\n");
    }
    String XmlUnitTestResultPrinter::TestPropertiesAsXmlAttributes (const
								    TestResult
								    & result)
    {
      Message attributes;
      for (int i = 0; i < result.test_property_count (); ++i)
	{
	  const TestProperty & property = result.GetTestProperty (i);
	  attributes << " " << property.key () << "="
	    << "\"" << EscapeXmlAttribute (property.value ()) << "\"";
	}
      return attributes.GetString ();
    }
    class StreamingListener:public EmptyTestEventListener
    {
    public:
      static string UrlEncode (const char *str);
        StreamingListener (const string & host,
			   const string & port):sockfd_ (-1),
	host_name_ (host), port_num_ (port)
      {
	MakeConnection ();
	Send ("gtest_streaming_protocol_version=1.0\n");
      }
      virtual ~ StreamingListener ()
      {
	if (sockfd_ != -1)
	  CloseConnection ();
      }
      void OnTestProgramStart (const UnitTest &)
      {
	Send ("event=TestProgramStart\n");
      }
      void OnTestProgramEnd (const UnitTest & unit_test)
      {
	Send (String::Format ("event=TestProgramEnd&passed=%d\n",
			      unit_test.Passed ()));
	CloseConnection ();
      }
      void OnTestIterationStart (const UnitTest &, int iteration)
      {
	Send (String::Format ("event=TestIterationStart&iteration=%d\n",
			      iteration));
      }
      void OnTestIterationEnd (const UnitTest & unit_test, int)
      {
	Send (String::Format
	      ("event=TestIterationEnd&passed=%d&elapsed_time=%sms\n",
	       unit_test.Passed (),
	       StreamableToString (unit_test.elapsed_time ()).c_str ()));
      }
      void OnTestCaseStart (const TestCase & test_case)
      {
	Send (String::Format
	      ("event=TestCaseStart&name=%s\n", test_case.name ()));
      }
      void OnTestCaseEnd (const TestCase & test_case)
      {
	Send (String::Format
	      ("event=TestCaseEnd&passed=%d&elapsed_time=%sms\n",
	       test_case.Passed (),
	       StreamableToString (test_case.elapsed_time ()).c_str ()));
      }
      void OnTestStart (const TestInfo & test_info)
      {
	Send (String::Format
	      ("event=TestStart&name=%s\n", test_info.name ()));
      }
      void OnTestEnd (const TestInfo & test_info)
      {
	Send (String::Format ("event=TestEnd&passed=%d&elapsed_time=%sms\n",
			      (test_info.result ())->Passed (),
			      StreamableToString ((test_info.result ())->
						  elapsed_time ()).c_str ()));
      }
      void OnTestPartResult (const TestPartResult & test_part_result)
      {
	const char *file_name = test_part_result.file_name ();
	if (file_name == __null)
	  file_name = "";
	Send (String::Format ("event=TestPartResult&file=%s&line=%d&message=",
			      UrlEncode (file_name).c_str (),
			      test_part_result.line_number ()));
	Send (UrlEncode (test_part_result.message ()) + "\n");
      }
    private:
      void MakeConnection ();
      void CloseConnection ()
      {
	switch (0)
	  case 0:
	  default:
	  if (::testing::internal::IsTrue (sockfd_ != -1));
	  else
	    ::testing::internal::GTestLog (::testing::internal::GTEST_FATAL,
					   "gtest.cc",
					   3408).GetStream () << "Condition "
	      "sockfd_ != -1" " failed. " <<
	      "CloseConnection() can be called only when there is a connection.";
	close (sockfd_);
	sockfd_ = -1;
      }
      void Send (const string & message)
      {
	switch (0)
	  case 0:
	  default:
	  if (::testing::internal::IsTrue (sockfd_ != -1));
	  else
	    ::testing::internal::GTestLog (::testing::internal::GTEST_FATAL,
					   "gtest.cc",
					   3417).GetStream () << "Condition "
	      "sockfd_ != -1" " failed. " <<
	      "Send() can be called only when there is a connection.";
	const int len = static_cast < int >(message.length ());
	if (write (sockfd_, message.c_str (), len) != len)
	  {
	    ::testing::internal::GTestLog (::testing::internal::GTEST_WARNING,
					   "gtest.cc",
					   3422).GetStream () <<
	      "stream_result_to: failed to stream to " << host_name_ << ":" <<
	      port_num_;
	  }
      }
      int sockfd_;
      const string host_name_;
      const string port_num_;
      StreamingListener (StreamingListener const &);
      void operator= (StreamingListener const &);
    };
    string StreamingListener::UrlEncode (const char *str)
    {
      string result;
      result.reserve (strlen (str) + 1);
      for (char ch = *str; ch != '\0'; ch = *++str)
	{
	  switch (ch)
	    {
	    case '%':
	    case '=':
	    case '&':
	    case '\n':
	      result.append (String::Format
			     ("%%%02x", static_cast < unsigned char >(ch)));
	      break;
	    default:
	      result.push_back (ch);
	      break;
	    }
	}
      return result;
    }
    void StreamingListener::MakeConnection ()
    {
      switch (0)
	case 0:
	default:
	if (::testing::internal::IsTrue (sockfd_ == -1));
	else
	  ::testing::internal::GTestLog (::testing::internal::GTEST_FATAL,
					 "gtest.cc",
					 3460).GetStream () << "Condition "
	    "sockfd_ == -1" " failed. " <<
	    "MakeConnection() can't be called when there is already a connection.";
      addrinfo hints;
      memset (&hints, 0, sizeof (hints));
      hints.ai_family = 0;
      hints.ai_socktype = SOCK_STREAM;
      addrinfo *servinfo = __null;
      const int error_num =
	getaddrinfo (host_name_.c_str (), port_num_.c_str (), &hints,
		     &servinfo);
      if (error_num != 0)
	{
	  ::testing::internal::GTestLog (::testing::internal::GTEST_WARNING,
					 "gtest.cc",
					 3474).GetStream () <<
	    "stream_result_to: getaddrinfo() failed: " <<
	    gai_strerror (error_num);
	}
      for (addrinfo * cur_addr = servinfo;
	   sockfd_ == -1 && cur_addr != __null; cur_addr = cur_addr->ai_next)
	{
	  sockfd_ =
	    socket (cur_addr->ai_family, cur_addr->ai_socktype,
		    cur_addr->ai_protocol);
	  if (sockfd_ != -1)
	    {
	      if (connect (sockfd_, cur_addr->ai_addr, cur_addr->ai_addrlen)
		  == -1)
		{
		  close (sockfd_);
		  sockfd_ = -1;
		}
	    }
	}
      freeaddrinfo (servinfo);
      if (sockfd_ == -1)
	{
	  ::testing::internal::GTestLog (::testing::internal::GTEST_WARNING,
					 "gtest.cc",
					 3495).GetStream () <<
	    "stream_result_to: failed to connect to " << host_name_ << ":" <<
	    port_num_;
	}
    }
    ScopedTrace::ScopedTrace (const char *file, int line,
			      const Message & message)
    {
      TraceInfo trace;
      trace.file = file;
      trace.line = line;
      trace.message = message.GetString ();
      UnitTest::GetInstance ()->PushGTestTrace (trace);
    }
    ScopedTrace::~ScopedTrace ()
    {
      UnitTest::GetInstance ()->PopGTestTrace ();
    }
    String OsStackTraceGetter::CurrentStackTrace (int, int)
    {
      return String ("");
    }
    void OsStackTraceGetter::UponLeavingGTest ()
    {
    }
    const char *const
      OsStackTraceGetter::kElidedFramesMarker =
      "... " "Google Test" " internal frames ...";
  }
TestEventListeners::TestEventListeners ():repeater_ (new internal::TestEventRepeater ()),
    default_result_printer_ (__null),
    default_xml_generator_ (__null)
  {
  }
  TestEventListeners::~TestEventListeners ()
  {
    delete repeater_;
  }
  void TestEventListeners::Append (TestEventListener * listener)
  {
    repeater_->Append (listener);
  }
  TestEventListener *TestEventListeners::Release (TestEventListener *
						  listener)
  {
    if (listener == default_result_printer_)
      default_result_printer_ = __null;
    else if (listener == default_xml_generator_)
      default_xml_generator_ = __null;
    return repeater_->Release (listener);
  }
  TestEventListener *TestEventListeners::repeater ()
  {
    return repeater_;
  }
  void TestEventListeners::SetDefaultResultPrinter (TestEventListener *
						    listener)
  {
    if (default_result_printer_ != listener)
      {
	delete Release (default_result_printer_);
	default_result_printer_ = listener;
	if (listener != __null)
	  Append (listener);
      }
  }
  void TestEventListeners::SetDefaultXmlGenerator (TestEventListener *
						   listener)
  {
    if (default_xml_generator_ != listener)
      {
	delete Release (default_xml_generator_);
	default_xml_generator_ = listener;
	if (listener != __null)
	  Append (listener);
      }
  }
  bool TestEventListeners::EventForwardingEnabled () const
  {
    return repeater_->forwarding_enabled ();
  }
  void TestEventListeners::SuppressEventForwarding ()
  {
    repeater_->set_forwarding_enabled (false);
  }
  UnitTest *UnitTest::GetInstance ()
  {
    static UnitTest instance;
    return &instance;
  }
  int UnitTest::successful_test_case_count () const
  {
    return impl ()->successful_test_case_count ();
  }
  int UnitTest::failed_test_case_count () const
  {
    return impl ()->failed_test_case_count ();
  }
  int UnitTest::total_test_case_count () const
  {
    return impl ()->total_test_case_count ();
  }
  int UnitTest::test_case_to_run_count () const
  {
    return impl ()->test_case_to_run_count ();
  }
  int UnitTest::successful_test_count () const
  {
    return impl ()->successful_test_count ();
  }
  int UnitTest::failed_test_count () const
  {
    return impl ()->failed_test_count ();
  }
  int UnitTest::disabled_test_count () const
  {
    return impl ()->disabled_test_count ();
  }
  int UnitTest::total_test_count () const
  {
    return impl ()->total_test_count ();
  }
  int UnitTest::test_to_run_count () const
  {
    return impl ()->test_to_run_count ();
  }
  internal::TimeInMillis UnitTest::elapsed_time () const
  {
    return impl ()->elapsed_time ();
  }
  bool UnitTest::Passed () const
  {
    return impl ()->Passed ();
  }
  bool UnitTest::Failed () const
  {
    return impl ()->Failed ();
  }
  const TestCase *UnitTest::GetTestCase (int i) const
  {
    return impl ()->GetTestCase (i);
  }
  TestCase *UnitTest::GetMutableTestCase (int i)
  {
    return impl ()->GetMutableTestCase (i);
  }
  TestEventListeners & UnitTest::listeners ()
  {
    return *impl ()->listeners ();
  }
  Environment *UnitTest::AddEnvironment (Environment * env)
  {
    if (env == __null)
      {
	return __null;
      }
    impl_->environments ().push_back (env);
    return env;
  }
  void UnitTest::AddTestPartResult (TestPartResult::Type result_type,
				    const char *file_name,
				    int line_number,
				    const internal::String & message,
				    const internal::String & os_stack_trace)
  {
    Message msg;
    msg << message;
    internal::MutexLock lock (&mutex_);
    if (impl_->gtest_trace_stack ().size () > 0)
      {
	msg << "\n" << "Google Test" << " trace:";
	for (int i = static_cast < int >(impl_->gtest_trace_stack ().size ());
	     i > 0; --i)
	  {
	    const internal::TraceInfo & trace =
	      impl_->gtest_trace_stack ()[i - 1];
	    msg << "\n" << internal::FormatFileLocation (trace.file,
							 trace.line) << " " <<
	      trace.message;
	  }
      }
    if (os_stack_trace.c_str () != __null && !os_stack_trace.empty ())
      {
	msg << internal::kStackTraceMarker << os_stack_trace;
      }
    const TestPartResult result =
      TestPartResult (result_type, file_name, line_number,
		      msg.GetString ().c_str ());
    impl_->GetTestPartResultReporterForCurrentThread ()->ReportTestPartResult
      (result);
    if (result_type != TestPartResult::kSuccess)
      {
	if (FLAGS_gtest_break_on_failure)
	  {
	    *static_cast < volatile int *>(__null) = 1;
	  }
	else if (FLAGS_gtest_throw_on_failure)
	  {
	    throw GoogleTestFailureException (result);
	  }
      }
  }
  void UnitTest::RecordPropertyForCurrentTest (const char *key,
					       const char *value)
  {
    const TestProperty test_property (key, value);
    impl_->current_test_result ()->RecordProperty (test_property);
  }
  int UnitTest::Run ()
  {
    impl ()->set_catch_exceptions (FLAGS_gtest_catch_exceptions);
    return internal::HandleExceptionsInMethodIfSupported (impl (),
							  &internal::
							  UnitTestImpl::
							  RunAllTests,
							  "auxiliary test code (environments or event listeners)")
      ? 0 : 1;
  }
  const char *UnitTest::original_working_dir () const
  {
    return impl_->original_working_dir_.c_str ();
  }
  const TestCase *UnitTest::current_test_case () const
  {
    internal::MutexLock lock (&mutex_);
    return impl_->current_test_case ();
  }
  const TestInfo *UnitTest::current_test_info () const
  {
    internal::MutexLock lock (&mutex_);
    return impl_->current_test_info ();
  }
  int UnitTest::random_seed () const
  {
    return impl_->random_seed ();
  }
  internal::ParameterizedTestCaseRegistry &
    UnitTest::parameterized_test_registry ()
  {
    return impl_->parameterized_test_registry ();
  }
  UnitTest::UnitTest ()
  {
    impl_ = new internal::UnitTestImpl (this);
  }
  UnitTest::~UnitTest ()
  {
    delete impl_;
  }
  void UnitTest::PushGTestTrace (const internal::TraceInfo & trace)
  {
    internal::MutexLock lock (&mutex_);
    impl_->gtest_trace_stack ().push_back (trace);
  }
  void UnitTest::PopGTestTrace ()
  {
    internal::MutexLock lock (&mutex_);
    impl_->gtest_trace_stack ().pop_back ();
  }
  namespace internal
  {
    UnitTestImpl::UnitTestImpl (UnitTest * parent):parent_ (parent),
      default_global_test_part_result_reporter_ (this),
      default_per_thread_test_part_result_reporter_ (this),
      global_test_part_result_repoter_
      (&default_global_test_part_result_reporter_),
      per_thread_test_part_result_reporter_
      (&default_per_thread_test_part_result_reporter_),
      parameterized_test_registry_ (),
      parameterized_tests_registered_ (false), last_death_test_case_ (-1),
      current_test_case_ (__null), current_test_info_ (__null),
      ad_hoc_test_result_ (), os_stack_trace_getter_ (__null),
      post_flag_parse_init_performed_ (false), random_seed_ (0), random_ (0),
      elapsed_time_ (0), internal_run_death_test_flag_ (__null),
      death_test_factory_ (new DefaultDeathTestFactory),
      catch_exceptions_ (false)
    {
      listeners ()->SetDefaultResultPrinter (new PrettyUnitTestResultPrinter);
    }
    UnitTestImpl::~UnitTestImpl ()
    {
      ForEach (test_cases_, internal::Delete < TestCase >);
      ForEach (environments_, internal::Delete < Environment >);
      delete os_stack_trace_getter_;
    }
    void UnitTestImpl::SuppressTestEventsIfInSubprocess ()
    {
      if (internal_run_death_test_flag_.get () != __null)
	listeners ()->SuppressEventForwarding ();
    }
    void UnitTestImpl::ConfigureXmlOutput ()
    {
      const String & output_format = UnitTestOptions::GetOutputFormat ();
      if (output_format == "xml")
	{
	  listeners ()->SetDefaultXmlGenerator (new
						XmlUnitTestResultPrinter
						(UnitTestOptions::
						 GetAbsolutePathToOutputFile
						 ().c_str ()));
	}
      else if (output_format != "")
	{
	  printf ("WARNING: unrecognized output format \"%s\" ignored.\n",
		  output_format.c_str ());
	  fflush (stdout);
	}
    }
    void UnitTestImpl::ConfigureStreamingOutput ()
    {
      const string & target = FLAGS_gtest_stream_result_to;
      if (!target.empty ())
	{
	  const size_t pos = target.find (':');
	  if (pos != string::npos)
	    {
	      listeners ()->Append (new
				    StreamingListener (target.substr (0, pos),
						       target.substr (pos +
								      1)));
	    }
	  else
	    {
	      printf
		("WARNING: unrecognized streaming target \"%s\" ignored.\n",
		 target.c_str ());
	      fflush (stdout);
	    }
	}
    }
    void UnitTestImpl::PostFlagParsingInit ()
    {
      if (!post_flag_parse_init_performed_)
	{
	  post_flag_parse_init_performed_ = true;
	  InitDeathTestSubprocessControlInfo ();
	  SuppressTestEventsIfInSubprocess ();
	  RegisterParameterizedTests ();
	  ConfigureXmlOutput ();
	  ConfigureStreamingOutput ();
	}
    }
    class TestCaseNameIs
    {
    public:
      explicit TestCaseNameIs (const String & name):name_ (name)
      {
      }
      bool operator     () (const TestCase * test_case) const
      {
	return test_case != __null
	  && strcmp (test_case->name (), name_.c_str ()) == 0;
      }
    private:
        String name_;
    };
    TestCase *UnitTestImpl::GetTestCase (const char *test_case_name,
					 const char *type_param,
					 Test::SetUpTestCaseFunc set_up_tc,
					 Test::TearDownTestCaseFunc
					 tear_down_tc)
    {
      const std::vector < TestCase * >::const_iterator test_case =
	std::find_if (test_cases_.begin (), test_cases_.end (),
		      TestCaseNameIs (test_case_name));
      if (test_case != test_cases_.end ())
	return *test_case;
      TestCase *const new_test_case =
	new TestCase (test_case_name, type_param, set_up_tc, tear_down_tc);
      if (internal::UnitTestOptions::MatchesFilter (String (test_case_name),
						    kDeathTestCaseFilter))
	{
	  ++last_death_test_case_;
	  test_cases_.insert (test_cases_.begin () + last_death_test_case_,
			      new_test_case);
	}
      else
	{
	  test_cases_.push_back (new_test_case);
	}
      test_case_indices_.push_back (static_cast <
				    int >(test_case_indices_.size ()));
      return new_test_case;
    }
    static void SetUpEnvironment (Environment * env)
    {
      env->SetUp ();
    }
    static void TearDownEnvironment (Environment * env)
    {
      env->TearDown ();
    }
    bool UnitTestImpl::RunAllTests ()
    {
      if (!GTestIsInitialized ())
	{
	  printf ("%s",
		  "\nThis test program did NOT call ::testing::InitGoogleTest "
		  "before calling RUN_ALL_TESTS().  Please fix it.\n");
	  return false;
	}
      if (g_help_flag)
	return true;
      PostFlagParsingInit ();
      internal::WriteToShardStatusFileIfNeeded ();
      bool in_subprocess_for_death_test = false;
      in_subprocess_for_death_test =
	(internal_run_death_test_flag_.get () != __null);
      const bool should_shard =
	ShouldShard (kTestTotalShards, kTestShardIndex,
		     in_subprocess_for_death_test);
      const bool has_tests_to_run = FilterTests (should_shard
						 ? HONOR_SHARDING_PROTOCOL
						 : IGNORE_SHARDING_PROTOCOL) >
	0;
      if (FLAGS_gtest_list_tests)
	{
	  ListTestsMatchingFilter ();
	  return true;
	}
      random_seed_ = FLAGS_gtest_shuffle ?
	GetRandomSeedFromFlag (FLAGS_gtest_random_seed) : 0;
      bool failed = false;
      TestEventListener *repeater = listeners ()->repeater ();
      repeater->OnTestProgramStart (*parent_);
      const int repeat =
	in_subprocess_for_death_test ? 1 : FLAGS_gtest_repeat;
      const bool forever = repeat < 0;
      for (int i = 0; forever || i != repeat; i++)
	{
	  ClearNonAdHocTestResult ();
	  const TimeInMillis start = GetTimeInMillis ();
	  if (has_tests_to_run && FLAGS_gtest_shuffle)
	    {
	      random ()->Reseed (random_seed_);
	      ShuffleTests ();
	    }
	  repeater->OnTestIterationStart (*parent_, i);
	  if (has_tests_to_run)
	    {
	      repeater->OnEnvironmentsSetUpStart (*parent_);
	      ForEach (environments_, SetUpEnvironment);
	      repeater->OnEnvironmentsSetUpEnd (*parent_);
	      if (!Test::HasFatalFailure ())
		{
		  for (int test_index = 0;
		       test_index < total_test_case_count (); test_index++)
		    {
		      GetMutableTestCase (test_index)->Run ();
		    }
		}
	      repeater->OnEnvironmentsTearDownStart (*parent_);
	      std::for_each (environments_.rbegin (), environments_.rend (),
			     TearDownEnvironment);
	      repeater->OnEnvironmentsTearDownEnd (*parent_);
	    }
	  elapsed_time_ = GetTimeInMillis () - start;
	  repeater->OnTestIterationEnd (*parent_, i);
	  if (!Passed ())
	    {
	      failed = true;
	    }
	  UnshuffleTests ();
	  if (FLAGS_gtest_shuffle)
	    {
	      random_seed_ = GetNextRandomSeed (random_seed_);
	    }
	}
      repeater->OnTestProgramEnd (*parent_);
      return !failed;
    }
    void WriteToShardStatusFileIfNeeded ()
    {
      const char *const test_shard_file =
	posix::GetEnv (kTestShardStatusFile);
      if (test_shard_file != __null)
	{
	  FILE *const file = posix::FOpen (test_shard_file, "w");
	  if (file == __null)
	    {
	      ColoredPrintf (COLOR_RED,
			     "Could not write to the test shard status file \"%s\" "
			     "specified by the %s environment variable.\n",
			     test_shard_file, kTestShardStatusFile);
	      fflush (stdout);
	      exit (1);
	    }
	  fclose (file);
	}
    }
    bool ShouldShard (const char *total_shards_env,
		      const char *shard_index_env,
		      bool in_subprocess_for_death_test)
    {
      if (in_subprocess_for_death_test)
	{
	  return false;
	}
      const Int32 total_shards = Int32FromEnvOrDie (total_shards_env, -1);
      const Int32 shard_index = Int32FromEnvOrDie (shard_index_env, -1);
      if (total_shards == -1 && shard_index == -1)
	{
	  return false;
	}
      else if (total_shards == -1 && shard_index != -1)
	{
	  const Message msg = Message ()
	    << "Invalid environment variables: you have "
	    << kTestShardIndex << " = " << shard_index
	    << ", but have left " << kTestTotalShards << " unset.\n";
	  ColoredPrintf (COLOR_RED, msg.GetString ().c_str ());
	  fflush (stdout);
	  exit (1);
	}
      else if (total_shards != -1 && shard_index == -1)
	{
	  const Message msg = Message ()
	    << "Invalid environment variables: you have "
	    << kTestTotalShards << " = " << total_shards
	    << ", but have left " << kTestShardIndex << " unset.\n";
	  ColoredPrintf (COLOR_RED, msg.GetString ().c_str ());
	  fflush (stdout);
	  exit (1);
	}
      else if (shard_index < 0 || shard_index >= total_shards)
	{
	  const Message msg = Message ()
	    << "Invalid environment variables: we require 0 <= "
	    << kTestShardIndex << " < " << kTestTotalShards
	    << ", but you have " << kTestShardIndex << "=" << shard_index
	    << ", " << kTestTotalShards << "=" << total_shards << ".\n";
	  ColoredPrintf (COLOR_RED, msg.GetString ().c_str ());
	  fflush (stdout);
	  exit (1);
	}
      return total_shards > 1;
    }
    Int32 Int32FromEnvOrDie (const char *var, Int32 default_val)
    {
      const char *str_val = posix::GetEnv (var);
      if (str_val == __null)
	{
	  return default_val;
	}
      Int32 result;
      if (!ParseInt32
	  (Message () << "The value of environment variable " << var, str_val,
	   &result))
	{
	  exit (1);
	}
      return result;
    }
    bool ShouldRunTestOnShard (int total_shards, int shard_index, int test_id)
    {
      return (test_id % total_shards) == shard_index;
    }
    int UnitTestImpl::FilterTests (ReactionToSharding shard_tests)
    {
      const Int32 total_shards = shard_tests == HONOR_SHARDING_PROTOCOL ?
	Int32FromEnvOrDie (kTestTotalShards, -1) : -1;
      const Int32 shard_index = shard_tests == HONOR_SHARDING_PROTOCOL ?
	Int32FromEnvOrDie (kTestShardIndex, -1) : -1;
      int num_runnable_tests = 0;
      int num_selected_tests = 0;
      for (size_t i = 0; i < test_cases_.size (); i++)
	{
	  TestCase *const test_case = test_cases_[i];
	  const String & test_case_name = test_case->name ();
	  test_case->set_should_run (false);
	  for (size_t j = 0; j < test_case->test_info_list ().size (); j++)
	    {
	      TestInfo *const test_info = test_case->test_info_list ()[j];
	      const String test_name (test_info->name ());
	      const bool is_disabled =
		internal::UnitTestOptions::MatchesFilter (test_case_name,
							  kDisableTestFilter)
		|| internal::UnitTestOptions::MatchesFilter (test_name,
							     kDisableTestFilter);
	      test_info->is_disabled_ = is_disabled;
	      const bool matches_filter =
		internal::UnitTestOptions::FilterMatchesTest (test_case_name,
							      test_name);
	      test_info->matches_filter_ = matches_filter;
	      const bool is_runnable =
		(FLAGS_gtest_also_run_disabled_tests || !is_disabled) &&
		matches_filter;
	      const bool is_selected = is_runnable &&
		(shard_tests == IGNORE_SHARDING_PROTOCOL ||
		 ShouldRunTestOnShard (total_shards, shard_index,
				       num_runnable_tests));
	      num_runnable_tests += is_runnable;
	      num_selected_tests += is_selected;
	      test_info->should_run_ = is_selected;
	      test_case->set_should_run (test_case->should_run ()
					 || is_selected);
	    }
	}
      return num_selected_tests;
    }
    void UnitTestImpl::ListTestsMatchingFilter ()
    {
      for (size_t i = 0; i < test_cases_.size (); i++)
	{
	  const TestCase *const test_case = test_cases_[i];
	  bool printed_test_case_name = false;
	  for (size_t j = 0; j < test_case->test_info_list ().size (); j++)
	    {
	      const TestInfo *const test_info =
		test_case->test_info_list ()[j];
	      if (test_info->matches_filter_)
		{
		  if (!printed_test_case_name)
		    {
		      printed_test_case_name = true;
		      printf ("%s.\n", test_case->name ());
		    }
		  printf ("  %s\n", test_info->name ());
		}
	    }
	}
      fflush (stdout);
    }
    void UnitTestImpl::set_os_stack_trace_getter (OsStackTraceGetterInterface
						  * getter)
    {
      if (os_stack_trace_getter_ != getter)
	{
	  delete os_stack_trace_getter_;
	  os_stack_trace_getter_ = getter;
	}
    }
    OsStackTraceGetterInterface *UnitTestImpl::os_stack_trace_getter ()
    {
      if (os_stack_trace_getter_ == __null)
	{
	  os_stack_trace_getter_ = new OsStackTraceGetter;
	}
      return os_stack_trace_getter_;
    }
    TestResult *UnitTestImpl::current_test_result ()
    {
      return current_test_info_ ?
	&(current_test_info_->result_) : &ad_hoc_test_result_;
    }
    void UnitTestImpl::ShuffleTests ()
    {
      ShuffleRange (random (), 0, last_death_test_case_ + 1,
		    &test_case_indices_);
      ShuffleRange (random (), last_death_test_case_ + 1,
		    static_cast < int >(test_cases_.size ()),
		    &test_case_indices_);
      for (size_t i = 0; i < test_cases_.size (); i++)
	{
	  test_cases_[i]->ShuffleTests (random ());
	}
    }
    void UnitTestImpl::UnshuffleTests ()
    {
      for (size_t i = 0; i < test_cases_.size (); i++)
	{
	  test_cases_[i]->UnshuffleTests ();
	  test_case_indices_[i] = static_cast < int >(i);
	}
    }
    String GetCurrentOsStackTraceExceptTop (UnitTest *, int skip_count)
    {
      return GetUnitTestImpl ()->CurrentOsStackTraceExceptTop (skip_count +
							       1);
    }
    namespace
    {
      class ClassUniqueToAlwaysTrue
      {
      };
    }
    bool IsTrue (bool condition)
    {
      return condition;
    }
    bool AlwaysTrue ()
    {
      if (IsTrue (false))
	throw ClassUniqueToAlwaysTrue ();
      return true;
    }
    bool SkipPrefix (const char *prefix, const char **pstr)
    {
      const size_t prefix_len = strlen (prefix);
      if (strncmp (*pstr, prefix, prefix_len) == 0)
	{
	  *pstr += prefix_len;
	  return true;
	}
      return false;
    }
    const char *ParseFlagValue (const char *str,
				const char *flag, bool def_optional)
    {
      if (str == __null || flag == __null)
	return __null;
      const String flag_str = String::Format ("--%s%s", "gtest_", flag);
      const size_t flag_len = flag_str.length ();
      if (strncmp (str, flag_str.c_str (), flag_len) != 0)
	return __null;
      const char *flag_end = str + flag_len;
      if (def_optional && (flag_end[0] == '\0'))
	{
	  return flag_end;
	}
      if (flag_end[0] != '=')
	return __null;
      return flag_end + 1;
    }
    bool ParseBoolFlag (const char *str, const char *flag, bool * value)
    {
      const char *const value_str = ParseFlagValue (str, flag, true);
      if (value_str == __null)
	return false;
      *value = !(*value_str == '0' || *value_str == 'f' || *value_str == 'F');
      return true;
    }
    bool ParseInt32Flag (const char *str, const char *flag, Int32 * value)
    {
      const char *const value_str = ParseFlagValue (str, flag, false);
      if (value_str == __null)
	return false;
      return ParseInt32 (Message () << "The value of flag --" << flag,
			 value_str, value);
    }
    bool ParseStringFlag (const char *str, const char *flag, String * value)
    {
      const char *const value_str = ParseFlagValue (str, flag, false);
      if (value_str == __null)
	return false;
      *value = value_str;
      return true;
    }
    static bool HasGoogleTestFlagPrefix (const char *str)
    {
      return (SkipPrefix ("--", &str) ||
	      SkipPrefix ("-", &str) ||
	      SkipPrefix ("/", &str)) &&
	!SkipPrefix ("gtest_" "internal_", &str) &&
	(SkipPrefix ("gtest_", &str) || SkipPrefix ("gtest-", &str));
    }
    static void PrintColorEncoded (const char *str)
    {
      GTestColor color = COLOR_DEFAULT;
      for (;;)
	{
	  const char *p = strchr (str, '@');
	  if (p == __null)
	    {
	      ColoredPrintf (color, "%s", str);
	      return;
	    }
	  ColoredPrintf (color, "%s", String (str, p - str).c_str ());
	  const char ch = p[1];
	  str = p + 2;
	  if (ch == '@')
	    {
	      ColoredPrintf (color, "@");
	    }
	  else if (ch == 'D')
	    {
	      color = COLOR_DEFAULT;
	    }
	  else if (ch == 'R')
	    {
	      color = COLOR_RED;
	    }
	  else if (ch == 'G')
	    {
	      color = COLOR_GREEN;
	    }
	  else if (ch == 'Y')
	    {
	      color = COLOR_YELLOW;
	    }
	  else
	    {
	      --str;
	    }
	}
    }
    static const char kColorEncodedHelpMessage[] =
      "This program contains tests written using " "Google Test"
      ". You can use the\n"
      "following command line flags to control its behavior:\n" "\n"
      "Test Selection:\n" "  @G--" "gtest_" "list_tests@D\n"
      "      List the names of all tests instead of running them. The name of\n"
      "      TEST(Foo, Bar) is \"Foo.Bar\".\n" "  @G--" "gtest_"
      "filter=@YPOSTIVE_PATTERNS" "[@G-@YNEGATIVE_PATTERNS]@D\n"
      "      Run only the tests whose name matches one of the positive patterns but\n"
      "      none of the negative patterns. '?' matches any single character; '*'\n"
      "      matches any substring; ':' separates two patterns.\n" "  @G--"
      "gtest_" "also_run_disabled_tests@D\n"
      "      Run all disabled tests too.\n" "\n" "Test Execution:\n" "  @G--"
      "gtest_" "repeat=@Y[COUNT]@D\n"
      "      Run the tests repeatedly; use a negative count to repeat forever.\n"
      "  @G--" "gtest_" "shuffle@D\n"
      "      Randomize tests' orders on every iteration.\n" "  @G--" "gtest_"
      "random_seed=@Y[NUMBER]@D\n"
      "      Random number seed to use for shuffling test orders (between 1 and\n"
      "      99999, or 0 to use a seed based on the current time).\n" "\n"
      "Test Output:\n" "  @G--" "gtest_"
      "color=@Y(@Gyes@Y|@Gno@Y|@Gauto@Y)@D\n"
      "      Enable/disable colored output. The default is @Gauto@D.\n"
      "  -@G-" "gtest_" "print_time=0@D\n"
      "      Don't print the elapsed time of each test.\n" "  @G--" "gtest_"
      "output=xml@Y[@G:@YDIRECTORY_PATH@G" "/" "@Y|@G:@YFILE_PATH]@D\n"
      "      Generate an XML report in the given directory or with the given file\n"
      "      name. @YFILE_PATH@D defaults to @Gtest_details.xml@D.\n" "  @G--"
      "gtest_" "stream_result_to=@YHOST@G:@YPORT@D\n"
      "      Stream test results to the given server.\n" "\n"
      "Assertion Behavior:\n" "  @G--" "gtest_"
      "death_test_style=@Y(@Gfast@Y|@Gthreadsafe@Y)@D\n"
      "      Set the default death test style.\n" "  @G--" "gtest_"
      "break_on_failure@D\n"
      "      Turn assertion failures into debugger break-points.\n" "  @G--"
      "gtest_" "throw_on_failure@D\n"
      "      Turn assertion failures into C++ exceptions.\n" "  @G--" "gtest_"
      "catch_exceptions=0@D\n"
      "      Do not report exceptions as test failures. Instead, allow them\n"
      "      to crash the program or throw a pop-up (on Windows).\n" "\n"
      "Except for @G--" "gtest_" "list_tests@D, you can alternatively set "
      "the corresponding\n"
      "environment variable of a flag (all letters in upper-case). For example, to\n"
      "disable colored text output, you can either specify @G--" "gtest_"
      "color=no@D or set\n" "the @G" "GTEST_"
      "COLOR@D environment variable to @Gno@D.\n" "\n"
      "For more information, please read the " "Google Test"
      " documentation at\n" "@G" "http://code.google.com/p/googletest/"
      "@D. If you find a bug in " "Google Test" "\n"
      "(not one in your own code or tests), please report it to\n" "@G<"
      "googletestframework@@googlegroups.com" ">@D.\n";
    template < typename CharType >
      void ParseGoogleTestFlagsOnlyImpl (int *argc, CharType ** argv)
    {
      for (int i = 1; i < *argc; i++)
	{
	  const String arg_string = StreamableToString (argv[i]);
	  const char *const arg = arg_string.c_str ();
	  using internal::ParseBoolFlag;
	  using internal::ParseInt32Flag;
	  using internal::ParseStringFlag;
	  if (ParseBoolFlag (arg, kAlsoRunDisabledTestsFlag,
			     &FLAGS_gtest_also_run_disabled_tests) ||
	      ParseBoolFlag (arg, kBreakOnFailureFlag,
			     &FLAGS_gtest_break_on_failure) ||
	      ParseBoolFlag (arg, kCatchExceptionsFlag,
			     &FLAGS_gtest_catch_exceptions) ||
	      ParseStringFlag (arg, kColorFlag, &FLAGS_gtest_color) ||
	      ParseStringFlag (arg, kDeathTestStyleFlag,
			       &FLAGS_gtest_death_test_style) ||
	      ParseBoolFlag (arg, kDeathTestUseFork,
			     &FLAGS_gtest_death_test_use_fork) ||
	      ParseStringFlag (arg, kFilterFlag, &FLAGS_gtest_filter) ||
	      ParseStringFlag (arg, kInternalRunDeathTestFlag,
			       &FLAGS_gtest_internal_run_death_test) ||
	      ParseBoolFlag (arg, kListTestsFlag, &FLAGS_gtest_list_tests) ||
	      ParseStringFlag (arg, kOutputFlag, &FLAGS_gtest_output) ||
	      ParseBoolFlag (arg, kPrintTimeFlag, &FLAGS_gtest_print_time) ||
	      ParseInt32Flag (arg, kRandomSeedFlag, &FLAGS_gtest_random_seed)
	      || ParseInt32Flag (arg, kRepeatFlag, &FLAGS_gtest_repeat)
	      || ParseBoolFlag (arg, kShuffleFlag, &FLAGS_gtest_shuffle)
	      || ParseInt32Flag (arg, kStackTraceDepthFlag,
				 &FLAGS_gtest_stack_trace_depth)
	      || ParseStringFlag (arg, kStreamResultToFlag,
				  &FLAGS_gtest_stream_result_to)
	      || ParseBoolFlag (arg, kThrowOnFailureFlag,
				&FLAGS_gtest_throw_on_failure))
	    {
	      for (int j = i; j != *argc; j++)
		{
		  argv[j] = argv[j + 1];
		}
	      (*argc)--;
	      i--;
	    }
	  else if (arg_string == "--help" || arg_string == "-h" ||
		   arg_string == "-?" || arg_string == "/?" ||
		   HasGoogleTestFlagPrefix (arg))
	    {
	      g_help_flag = true;
	    }
	}
      if (g_help_flag)
	{
	  PrintColorEncoded (kColorEncodedHelpMessage);
	}
    }
    void ParseGoogleTestFlagsOnly (int *argc, char **argv)
    {
      ParseGoogleTestFlagsOnlyImpl (argc, argv);
    }
    void ParseGoogleTestFlagsOnly (int *argc, wchar_t ** argv)
    {
      ParseGoogleTestFlagsOnlyImpl (argc, argv);
    }
    template < typename CharType >
      void InitGoogleTestImpl (int *argc, CharType ** argv)
    {
      g_init_gtest_count++;
      if (g_init_gtest_count != 1)
	return;
      if (*argc <= 0)
	return;
      internal::g_executable_path = internal::StreamableToString (argv[0]);
      g_argvs.clear ();
      for (int i = 0; i != *argc; i++)
	{
	  g_argvs.push_back (StreamableToString (argv[i]));
	}
      ParseGoogleTestFlagsOnly (argc, argv);
      GetUnitTestImpl ()->PostFlagParsingInit ();
    }
  }
  void InitGoogleTest (int *argc, char **argv)
  {
    internal::InitGoogleTestImpl (argc, argv);
  }
  void InitGoogleTest (int *argc, wchar_t ** argv)
  {
    internal::InitGoogleTestImpl (argc, argv);
  }
}

namespace testing
{
  static const char kDefaultDeathTestStyle[] = "fast";
  ::testing::internal::String FLAGS_gtest_death_test_style =
    (internal::StringFromGTestEnv
     ("death_test_style", kDefaultDeathTestStyle));
  bool FLAGS_gtest_death_test_use_fork =
    (internal::BoolFromGTestEnv ("death_test_use_fork", false));
  namespace internal
  {
    ::testing::internal::String FLAGS_gtest_internal_run_death_test = ("");
  }
  ExitedWithCode::ExitedWithCode (int exit_code):exit_code_ (exit_code)
  {
  }
  bool ExitedWithCode::operator     () (int exit_status) const
  {
    return ((((*(int *) &(exit_status))) & 0x7f) == 0)
      && ((((*(int *) &(exit_status))) & 0xff00) >> 8) == exit_code_;
  }
  KilledBySignal::KilledBySignal (int signum):signum_ (signum)
  {
  }
  bool KilledBySignal::operator     () (int exit_status) const
  {
    return (((signed char) ((((*(int *) &(exit_status))) & 0x7f) + 1) >> 1) >
	    0) && (((*(int *) &(exit_status))) & 0x7f) == signum_;
  }
  namespace internal
  {
    static String ExitSummary (int exit_code)
    {
      Message m;
      if (((((*(int *) &(exit_code))) & 0x7f) == 0))
	{
	  m << "Exited with exit status " <<
	    ((((*(int *) &(exit_code))) & 0xff00) >> 8);
	}
      else
	if ((((signed char) ((((*(int *) &(exit_code))) & 0x7f) + 1) >> 1) >
	     0))
	{
	  m << "Terminated by signal " << (((*(int *) &(exit_code))) & 0x7f);
	}
      if ((((*(int *) &(exit_code))) & 0x80))
	{
	  m << " (core dumped)";
	}
      return m.GetString ();
    }
    bool ExitedUnsuccessfully (int exit_status)
    {
      return !ExitedWithCode (0) (exit_status);
    }
    static String DeathTestThreadWarning (size_t thread_count)
    {
      Message msg;
      msg << "Death tests use fork(), which is unsafe particularly"
	<< " in a threaded context. For this test, " << "Google Test" << " ";
      if (thread_count == 0)
	msg << "couldn't detect the number of threads.";
      else
	msg << "detected " << thread_count << " threads.";
      return msg.GetString ();
    }
    static const char kDeathTestLived = 'L';
    static const char kDeathTestReturned = 'R';
    static const char kDeathTestThrew = 'T';
    static const char kDeathTestInternalError = 'I';
    enum DeathTestOutcome
    { IN_PROGRESS, DIED, LIVED, RETURNED, THREW };
    void DeathTestAbort (const String & message)
    {
      const InternalRunDeathTestFlag *const flag =
	GetUnitTestImpl ()->internal_run_death_test_flag ();
      if (flag != __null)
	{
	  FILE *parent = posix::FDOpen (flag->write_fd (), "w");
	  fputc (kDeathTestInternalError, parent);
	  fprintf (parent, "%s", message.c_str ());
	  fflush (parent);
	  _exit (1);
	}
      else
	{
	  fprintf (stderr, "%s", message.c_str ());
	  fflush (stderr);
	  posix::Abort ();
	}
    }
    String GetLastErrnoDescription ()
    {
      return String ((*__errno_location ()) ==
		     0 ? "" : posix::StrError ((*__errno_location ())));
    }
    static void FailFromInternalError (int fd)
    {
      Message error;
      char buffer[256];
      int num_read;
      do
	{
	  while ((num_read = posix::Read (fd, buffer, 255)) > 0)
	    {
	      buffer[num_read] = '\0';
	      error << buffer;
	    }
	}
      while (num_read == -1 && (*__errno_location ()) == 4);
      if (num_read == 0)
	{
	  ::testing::internal::GTestLog (::testing::internal::GTEST_FATAL,
					 "gtest-death-test.cc",
					 285).GetStream () << error.
	    GetString ();
	}
      else
	{
	  const int last_error = (*__errno_location ());
	  ::testing::internal::GTestLog (::testing::internal::GTEST_FATAL,
					 "gtest-death-test.cc",
					 288).GetStream () <<
	    "Error while reading death test internal: " <<
	    GetLastErrnoDescription () << " [" << last_error << "]";
	}
    }
    DeathTest::DeathTest ()
    {
      TestInfo *const info = GetUnitTestImpl ()->current_test_info ();
      if (info == __null)
	{
	  DeathTestAbort ("Cannot run a death test outside of a TEST or "
			  "TEST_F construct");
	}
    }
    bool DeathTest::Create (const char *statement, const RE * regex,
			    const char *file, int line, DeathTest ** test)
    {
      return GetUnitTestImpl ()->death_test_factory ()->Create (statement,
								regex, file,
								line, test);
    }
    const char *DeathTest::LastMessage ()
    {
      return last_death_test_message_.c_str ();
    }
    void DeathTest::set_last_death_test_message (const String & message)
    {
      last_death_test_message_ = message;
    }
    String DeathTest::last_death_test_message_;
    class DeathTestImpl:public DeathTest
    {
    protected:
      DeathTestImpl (const char *a_statement,
		     const RE * a_regex):statement_ (a_statement),
	regex_ (a_regex), spawned_ (false), status_ (-1),
	outcome_ (IN_PROGRESS), read_fd_ (-1), write_fd_ (-1)
      {
      }
       ~DeathTestImpl ()
      {
	do
	  {
	    if (!::testing::internal::IsTrue (read_fd_ == -1))
	      {
		DeathTestAbort (::testing::internal::String::Format
				("CHECK failed: File %s, line %d: %s",
				 "gtest-death-test.cc", 334,
				 "read_fd_ == -1"));
	      }
	  }
	while (::testing::internal::AlwaysFalse ());
      }
      void Abort (AbortReason reason);
      virtual bool Passed (bool status_ok);
      const char *statement () const
      {
	return statement_;
      }
      const RE *regex () const
      {
	return regex_;
      }
      bool spawned () const
      {
	return spawned_;
      }
      void set_spawned (bool is_spawned)
      {
	spawned_ = is_spawned;
      }
      int status () const
      {
	return status_;
      }
      void set_status (int a_status)
      {
	status_ = a_status;
      }
      DeathTestOutcome outcome () const
      {
	return outcome_;
      }
      void set_outcome (DeathTestOutcome an_outcome)
      {
	outcome_ = an_outcome;
      }
      int read_fd () const
      {
	return read_fd_;
      }
      void set_read_fd (int fd)
      {
	read_fd_ = fd;
      }
      int write_fd () const
      {
	return write_fd_;
      }
      void set_write_fd (int fd)
      {
	write_fd_ = fd;
      }
      void ReadAndInterpretStatusByte ();
    private:
      const char *const statement_;
      const RE *const regex_;
      bool spawned_;
      int status_;
      DeathTestOutcome outcome_;
      int read_fd_;
      int write_fd_;
    };
    void DeathTestImpl::ReadAndInterpretStatusByte ()
    {
      char flag;
      int bytes_read;
      do
	{
	  bytes_read = posix::Read (read_fd (), &flag, 1);
	}
      while (bytes_read == -1 && (*__errno_location ()) == 4);
      if (bytes_read == 0)
	{
	  set_outcome (DIED);
	}
      else if (bytes_read == 1)
	{
	  switch (flag)
	    {
	    case kDeathTestReturned:
	      set_outcome (RETURNED);
	      break;
	    case kDeathTestThrew:
	      set_outcome (THREW);
	      break;
	    case kDeathTestLived:
	      set_outcome (LIVED);
	      break;
	    case kDeathTestInternalError:
	      FailFromInternalError (read_fd ());
	      break;
	    default:
	      ::testing::internal::GTestLog (::testing::internal::GTEST_FATAL,
					     "gtest-death-test.cc",
					     414).GetStream () <<
		"Death test child process reported " <<
		"unexpected status byte (" << static_cast <
		unsigned int >(flag) << ")";
	    }
	}
      else
	{
	  ::testing::internal::GTestLog (::testing::internal::GTEST_FATAL,
					 "gtest-death-test.cc",
					 419).GetStream () <<
	    "Read from death test child process failed: " <<
	    GetLastErrnoDescription ();
	}
      do
	{
	  int gtest_retval;
	  do
	    {
	      gtest_retval = (posix::Close (read_fd ()));
	    }
	  while (gtest_retval == -1 && (*__errno_location ()) == 4);
	  if (gtest_retval == -1)
	    {
	      DeathTestAbort (::testing::internal::String::Format
			      ("CHECK failed: File %s, line %d: %s != -1",
			       "gtest-death-test.cc", 422,
			       "posix::Close(read_fd())"));
	    }
	}
      while (::testing::internal::AlwaysFalse ());
      set_read_fd (-1);
    }
    void DeathTestImpl::Abort (AbortReason reason)
    {
      const char status_ch =
	reason == TEST_DID_NOT_DIE ? kDeathTestLived :
	reason == TEST_THREW_EXCEPTION ? kDeathTestThrew : kDeathTestReturned;
      do
	{
	  int gtest_retval;
	  do
	    {
	      gtest_retval = (posix::Write (write_fd (), &status_ch, 1));
	    }
	  while (gtest_retval == -1 && (*__errno_location ()) == 4);
	  if (gtest_retval == -1)
	    {
	      DeathTestAbort (::testing::internal::String::Format
			      ("CHECK failed: File %s, line %d: %s != -1",
			       "gtest-death-test.cc", 438,
			       "posix::Write(write_fd(), &status_ch, 1)"));
	    }
	}
      while (::testing::internal::AlwaysFalse ());
      _exit (1);
    }
    static::std::string FormatDeathTestOutput (const::std::string & output)
    {
      ::std::string ret;
      for (size_t at = 0;;)
	{
	  const size_t line_end = output.find ('\n', at);
	  ret += "[  DEATH   ] ";
	  if (line_end ==::std::string::npos)
	    {
	      ret += output.substr (at);
	      break;
	    }
	  ret += output.substr (at, line_end + 1 - at);
	  at = line_end + 1;
	}
      return ret;
    }
    bool DeathTestImpl::Passed (bool status_ok)
    {
      if (!spawned ())
	return false;
      const String error_message = GetCapturedStderr ();
      bool success = false;
      Message buffer;
      buffer << "Death test: " << statement () << "\n";
      switch (outcome ())
	{
	case LIVED:
	  buffer << "    Result: failed to die.\n"
	    << " Error msg:\n" << FormatDeathTestOutput (error_message);
	  break;
	case THREW:
	  buffer << "    Result: threw an exception.\n"
	    << " Error msg:\n" << FormatDeathTestOutput (error_message);
	  break;
	case RETURNED:
	  buffer << "    Result: illegal return in test statement.\n"
	    << " Error msg:\n" << FormatDeathTestOutput (error_message);
	  break;
	case DIED:
	  if (status_ok)
	    {
	      const bool matched =
		RE::PartialMatch (error_message.c_str (), *regex ());
	      if (matched)
		{
		  success = true;
		}
	      else
		{
		  buffer << "    Result: died but not with expected error.\n"
		    << "  Expected: " << regex ()->pattern () << "\n"
		    << "Actual msg:\n" <<
		    FormatDeathTestOutput (error_message);
		}
	    }
	  else
	    {
	      buffer << "    Result: died but not with expected exit code:\n"
		<< "            " << ExitSummary (status ()) << "\n"
		<< "Actual msg:\n" << FormatDeathTestOutput (error_message);
	    }
	  break;
	case IN_PROGRESS:
	default:
	  ::testing::internal::GTestLog (::testing::internal::GTEST_FATAL,
					 "gtest-death-test.cc",
					 531).GetStream () <<
	    "DeathTest::Passed somehow called before conclusion of test";
	}
      DeathTest::set_last_death_test_message (buffer.GetString ());
      return success;
    }
    class ForkingDeathTest:public DeathTestImpl
    {
    public:
      ForkingDeathTest (const char *statement, const RE * regex);
      virtual int Wait ();
    protected:
      void set_child_pid (pid_t child_pid)
      {
	child_pid_ = child_pid;
      }
    private:
        pid_t child_pid_;
    };
    ForkingDeathTest::ForkingDeathTest (const char *a_statement,
					const RE *
					a_regex):DeathTestImpl (a_statement,
								a_regex),
      child_pid_ (-1)
    {
    }
    int ForkingDeathTest::Wait ()
    {
      if (!spawned ())
	return 0;
      ReadAndInterpretStatusByte ();
      int status_value;
      do
	{
	  int gtest_retval;
	  do
	    {
	      gtest_retval = (waitpid (child_pid_, &status_value, 0));
	    }
	  while (gtest_retval == -1 && (*__errno_location ()) == 4);
	  if (gtest_retval == -1)
	    {
	      DeathTestAbort (::testing::internal::String::Format
			      ("CHECK failed: File %s, line %d: %s != -1",
			       "gtest-death-test.cc", 770,
			       "waitpid(child_pid_, &status_value, 0)"));
	    }
	}
      while (::testing::internal::AlwaysFalse ());
      set_status (status_value);
      return status_value;
    }
    class NoExecDeathTest:public ForkingDeathTest
    {
    public:
      NoExecDeathTest (const char *a_statement,
		       const RE * a_regex):ForkingDeathTest (a_statement,
							     a_regex)
      {
      }
      virtual TestRole AssumeRole ();
    };
    DeathTest::TestRole NoExecDeathTest::AssumeRole ()
    {
      const size_t thread_count = GetThreadCount ();
      if (thread_count != 1)
	{
	  ::testing::internal::GTestLog (::testing::internal::GTEST_WARNING,
					 "gtest-death-test.cc",
					 789).GetStream () <<
	    DeathTestThreadWarning (thread_count);
	}
      int pipe_fd[2];
      do
	{
	  if (!::testing::internal::IsTrue (pipe (pipe_fd) != -1))
	    {
	      DeathTestAbort (::testing::internal::String::Format
			      ("CHECK failed: File %s, line %d: %s",
			       "gtest-death-test.cc", 793,
			       "pipe(pipe_fd) != -1"));
	    }
	}
      while (::testing::internal::AlwaysFalse ());
      DeathTest::set_last_death_test_message ("");
      CaptureStderr ();
      FlushInfoLog ();
      const pid_t child_pid = fork ();
      do
	{
	  if (!::testing::internal::IsTrue (child_pid != -1))
	    {
	      DeathTestAbort (::testing::internal::String::Format
			      ("CHECK failed: File %s, line %d: %s",
			       "gtest-death-test.cc", 807,
			       "child_pid != -1"));
	    }
	}
      while (::testing::internal::AlwaysFalse ());
      set_child_pid (child_pid);
      if (child_pid == 0)
	{
	  do
	    {
	      int gtest_retval;
	      do
		{
		  gtest_retval = (close (pipe_fd[0]));
		}
	      while (gtest_retval == -1 && (*__errno_location ()) == 4);
	      if (gtest_retval == -1)
		{
		  DeathTestAbort (::testing::internal::String::Format
				  ("CHECK failed: File %s, line %d: %s != -1",
				   "gtest-death-test.cc", 810,
				   "close(pipe_fd[0])"));
		}
	    }
	  while (::testing::internal::AlwaysFalse ());
	  set_write_fd (pipe_fd[1]);
	  LogToStderr ();
	  GetUnitTestImpl ()->listeners ()->SuppressEventForwarding ();
	  return EXECUTE_TEST;
	}
      else
	{
	  do
	    {
	      int gtest_retval;
	      do
		{
		  gtest_retval = (close (pipe_fd[1]));
		}
	      while (gtest_retval == -1 && (*__errno_location ()) == 4);
	      if (gtest_retval == -1)
		{
		  DeathTestAbort (::testing::internal::String::Format
				  ("CHECK failed: File %s, line %d: %s != -1",
				   "gtest-death-test.cc", 821,
				   "close(pipe_fd[1])"));
		}
	    }
	  while (::testing::internal::AlwaysFalse ());
	  set_read_fd (pipe_fd[0]);
	  set_spawned (true);
	  return OVERSEE_TEST;
	}
    }
    class ExecDeathTest:public ForkingDeathTest
    {
    public:
      ExecDeathTest (const char *a_statement, const RE * a_regex,
		     const char *file,
		     int line):ForkingDeathTest (a_statement, a_regex),
	file_ (file), line_ (line)
      {
      }
      virtual TestRole AssumeRole ();
    private:
      const char *const file_;
      const int line_;
    };
    class Arguments
    {
    public:
      Arguments ()
      {
	args_.push_back (__null);
      }
       ~Arguments ()
      {
	for (std::vector < char *>::iterator i = args_.begin ();
	     i != args_.end (); ++i)
	  {
	    free (*i);
	  }
      }
      void AddArgument (const char *argument)
      {
	args_.insert (args_.end () - 1, posix::StrDup (argument));
      }
      template < typename Str >
	void AddArguments (const::std::vector < Str > &arguments)
      {
	for (typename::std::vector < Str >::const_iterator i =
	     arguments.begin (); i != arguments.end (); ++i)
	  {
	    args_.insert (args_.end () - 1, posix::StrDup (i->c_str ()));
	  }
      }
      char *const *Argv ()
      {
	return &args_[0];
      }
    private:
      std::vector < char *>args_;
    };
    struct ExecDeathTestArgs
    {
      char *const *argv;
      int close_fd;
    };
    extern "C" char **environ;
    inline char **GetEnviron ()
    {
      return environ;
    }
    static int ExecDeathTestChildMain (void *child_arg)
    {
      ExecDeathTestArgs *const args =
	static_cast < ExecDeathTestArgs * >(child_arg);
      do
	{
	  int gtest_retval;
	  do
	    {
	      gtest_retval = (close (args->close_fd));
	    }
	  while (gtest_retval == -1 && (*__errno_location ()) == 4);
	  if (gtest_retval == -1)
	    {
	      DeathTestAbort (::testing::internal::String::Format
			      ("CHECK failed: File %s, line %d: %s != -1",
			       "gtest-death-test.cc", 902,
			       "close(args->close_fd)"));
	    }
	}
      while (::testing::internal::AlwaysFalse ());
      const char *const original_dir =
	UnitTest::GetInstance ()->original_working_dir ();
      if (chdir (original_dir) != 0)
	{
	  DeathTestAbort (String::Format ("chdir(\"%s\") failed: %s",
					  original_dir,
					  GetLastErrnoDescription ().c_str
					  ()));
	  return 1;
	}
      execve (args->argv[0], args->argv, GetEnviron ());
      DeathTestAbort (String::Format ("execve(%s, ...) in %s failed: %s",
				      args->argv[0],
				      original_dir,
				      GetLastErrnoDescription ().c_str ()));
      return 1;
    }
    bool StackLowerThanAddress (const void *ptr) __attribute__ ((noinline));
    bool StackLowerThanAddress (const void *ptr)
    {
      int dummy;
      return &dummy < ptr;
    }
    bool StackGrowsDown ()
    {
      int dummy;
      return StackLowerThanAddress (&dummy);
    }
    static pid_t ExecDeathTestFork (char *const *argv, int close_fd)
    {
      ExecDeathTestArgs args = { argv, close_fd };
      pid_t child_pid = -1;
      const bool use_fork = FLAGS_gtest_death_test_use_fork;
      if (!use_fork)
	{
	  static const bool stack_grows_down = StackGrowsDown ();
	  const size_t stack_size = getpagesize ();
	  void *const stack = mmap (__null, stack_size, 0x1 | 0x2,
				    0x20 | 0x02, -1, 0);
	  do
	    {
	      if (!::testing::internal::IsTrue (stack != ((void *) -1)))
		{
		  DeathTestAbort (::testing::internal::String::Format
				  ("CHECK failed: File %s, line %d: %s",
				   "gtest-death-test.cc", 966,
				   "stack != MAP_FAILED"));
		}
	    }
	  while (::testing::internal::AlwaysFalse ());
	  void *const stack_top =
	    static_cast <
	    char *>(stack) + (stack_grows_down ? stack_size : 0);
	  child_pid = clone (&ExecDeathTestChildMain, stack_top, 17, &args);
	  do
	    {
	      if (!::testing::internal::
		  IsTrue (munmap (stack, stack_size) != -1))
		{
		  DeathTestAbort (::testing::internal::String::Format
				  ("CHECK failed: File %s, line %d: %s",
				   "gtest-death-test.cc", 972,
				   "munmap(stack, stack_size) != -1"));
		}
	    }
	  while (::testing::internal::AlwaysFalse ());
	}
      if (use_fork && (child_pid = fork ()) == 0)
	{
	  ExecDeathTestChildMain (&args);
	  _exit (0);
	}
      do
	{
	  if (!::testing::internal::IsTrue (child_pid != -1))
	    {
	      DeathTestAbort (::testing::internal::String::Format
			      ("CHECK failed: File %s, line %d: %s",
			       "gtest-death-test.cc", 983,
			       "child_pid != -1"));
	    }
	}
      while (::testing::internal::AlwaysFalse ());
      return child_pid;
    }
    DeathTest::TestRole ExecDeathTest::AssumeRole ()
    {
      const UnitTestImpl *const impl = GetUnitTestImpl ();
      const InternalRunDeathTestFlag *const flag =
	impl->internal_run_death_test_flag ();
      const TestInfo *const info = impl->current_test_info ();
      const int death_test_index = info->result ()->death_test_count ();
      if (flag != __null)
	{
	  set_write_fd (flag->write_fd ());
	  return EXECUTE_TEST;
	}
      int pipe_fd[2];
      do
	{
	  if (!::testing::internal::IsTrue (pipe (pipe_fd) != -1))
	    {
	      DeathTestAbort (::testing::internal::String::Format
			      ("CHECK failed: File %s, line %d: %s",
			       "gtest-death-test.cc", 1004,
			       "pipe(pipe_fd) != -1"));
	    }
	}
      while (::testing::internal::AlwaysFalse ());
      do
	{
	  if (!::testing::internal::IsTrue (fcntl (pipe_fd[1], 2, 0) != -1))
	    {
	      DeathTestAbort (::testing::internal::String::Format
			      ("CHECK failed: File %s, line %d: %s",
			       "gtest-death-test.cc", 1007,
			       "fcntl(pipe_fd[1], F_SETFD, 0) != -1"));
	    }
	}
      while (::testing::internal::AlwaysFalse ());
      const String filter_flag = String::Format ("--%s%s=%s.%s",
						 "gtest_", kFilterFlag,
						 info->test_case_name (),
						 info->name ());
      const String internal_flag = String::Format ("--%s%s=%s|%d|%d|%d",
						   "gtest_",
						   kInternalRunDeathTestFlag,
						   file_, line_,
						   death_test_index,
						   pipe_fd[1]);
      Arguments args;
      args.AddArguments (GetArgvs ());
      args.AddArgument (filter_flag.c_str ());
      args.AddArgument (internal_flag.c_str ());
      DeathTest::set_last_death_test_message ("");
      CaptureStderr ();
      FlushInfoLog ();
      const pid_t child_pid = ExecDeathTestFork (args.Argv (), pipe_fd[0]);
      do
	{
	  int gtest_retval;
	  do
	    {
	      gtest_retval = (close (pipe_fd[1]));
	    }
	  while (gtest_retval == -1 && (*__errno_location ()) == 4);
	  if (gtest_retval == -1)
	    {
	      DeathTestAbort (::testing::internal::String::Format
			      ("CHECK failed: File %s, line %d: %s != -1",
			       "gtest-death-test.cc", 1030,
			       "close(pipe_fd[1])"));
	    }
	}
      while (::testing::internal::AlwaysFalse ());
      set_child_pid (child_pid);
      set_read_fd (pipe_fd[0]);
      set_spawned (true);
      return OVERSEE_TEST;
    }
    bool DefaultDeathTestFactory::Create (const char *statement,
					  const RE * regex, const char *file,
					  int line, DeathTest ** test)
    {
      UnitTestImpl *const impl = GetUnitTestImpl ();
      const InternalRunDeathTestFlag *const flag =
	impl->internal_run_death_test_flag ();
      const int death_test_index =
	impl->current_test_info ()->increment_death_test_count ();
      if (flag != __null)
	{
	  if (death_test_index > flag->index ())
	    {
	      DeathTest::set_last_death_test_message (String::Format
						      ("Death test count (%d) somehow exceeded expected maximum (%d)",
						       death_test_index,
						       flag->index ()));
	      return false;
	    }
	  if (!(flag->file () == file && flag->line () == line &&
		flag->index () == death_test_index))
	    {
	      *test = __null;
	      return true;
	    }
	}
      if (FLAGS_gtest_death_test_style == "threadsafe")
	{
	  *test = new ExecDeathTest (statement, regex, file, line);
	}
      else if (FLAGS_gtest_death_test_style == "fast")
	{
	  *test = new NoExecDeathTest (statement, regex);
	}
      else
	{
	  DeathTest::set_last_death_test_message (String::Format
						  ("Unknown death test style \"%s\" encountered",
						   FLAGS_gtest_death_test_style.
						   c_str ()));
	  return false;
	}
      return true;
    }
    static void SplitString (const::std::string & str,
			     char delimiter,::std::vector <::std::string >
			     *dest)
    {
      ::std::vector <::std::string > parsed;
      ::std::string::size_type pos = 0;
      while (::testing::internal::AlwaysTrue ())
	{
	  const::std::string::size_type colon = str.find (delimiter, pos);
	  if (colon ==::std::string::npos)
	    {
	      parsed.push_back (str.substr (pos));
	      break;
	    }
	  else
	    {
	      parsed.push_back (str.substr (pos, colon - pos));
	      pos = colon + 1;
	    }
	}
      dest->swap (parsed);
    }
    InternalRunDeathTestFlag *ParseInternalRunDeathTestFlag ()
    {
      if (FLAGS_gtest_internal_run_death_test == "")
	return __null;
      int line = -1;
      int index = -1;
      ::std::vector <::std::string > fields;
      SplitString (FLAGS_gtest_internal_run_death_test.c_str (), '|',
		   &fields);
      int write_fd = -1;
      if (fields.size () != 4
	  || !ParseNaturalNumber (fields[1], &line)
	  || !ParseNaturalNumber (fields[2], &index)
	  || !ParseNaturalNumber (fields[3], &write_fd))
	{
	  DeathTestAbort (String::Format
			  ("Bad --gtest_internal_run_death_test flag: %s",
			   FLAGS_gtest_internal_run_death_test.c_str ()));
	}
      return new InternalRunDeathTestFlag (fields[0], line, index, write_fd);
    }
  }
}

namespace testing
{
  namespace internal
  {
    const char kPathSeparator = '/';
    const char kPathSeparatorString[] = "/";
    const char kCurrentDirectoryString[] = "./";
    static bool IsPathSeparator (char c)
    {
      return c == kPathSeparator;
    }
    FilePath FilePath::GetCurrentDir ()
    {
      char cwd[4096 + 1] = { '\0' };
      return FilePath (getcwd (cwd, sizeof (cwd)) == __null ? "" : cwd);
    }
    FilePath FilePath::RemoveExtension (const char *extension) const
    {
      String dot_extension (String::Format (".%s", extension));
      if (pathname_.EndsWithCaseInsensitive (dot_extension.c_str ()))
	{
	  return
	    FilePath (String (pathname_.c_str (), pathname_.length () - 4));
	}
      return *this;
    }
    const char *FilePath::FindLastPathSeparator () const
    {
      const char *const last_sep = strrchr (c_str (), kPathSeparator);
        return last_sep;
    }
    FilePath FilePath::RemoveDirectoryName () const
    {
      const char *const last_sep = FindLastPathSeparator ();
        return last_sep ? FilePath (String (last_sep + 1)) : *this;
    }
    FilePath FilePath::RemoveFileName () const
    {
      const char *const last_sep = FindLastPathSeparator ();
      String dir;
      if (last_sep)
	{
	  dir = String (c_str (), last_sep + 1 - c_str ());
	}
      else
	{
	  dir = kCurrentDirectoryString;
	}
      return FilePath (dir);
    }
    FilePath FilePath::MakeFileName (const FilePath & directory,
				     const FilePath & base_name,
				     int number, const char *extension)
    {
      String file;
      if (number == 0)
	{
	  file = String::Format ("%s.%s", base_name.c_str (), extension);
	}
      else
	{
	  file =
	    String::Format ("%s_%d.%s", base_name.c_str (), number,
			    extension);
	}
      return ConcatPaths (directory, FilePath (file));
    }
    FilePath FilePath::ConcatPaths (const FilePath & directory,
				    const FilePath & relative_path)
    {
      if (directory.IsEmpty ())
	return relative_path;
      const FilePath dir (directory.RemoveTrailingPathSeparator ());
      return FilePath (String::Format ("%s%c%s", dir.c_str (), kPathSeparator,
				       relative_path.c_str ()));
    }
    bool FilePath::FileOrDirectoryExists () const
    {
      posix::StatStruct file_stat;
      return posix::Stat (pathname_.c_str (), &file_stat) == 0;
    }
    bool FilePath::DirectoryExists () const
    {
      bool result = false;
      const FilePath & path (*this);
        posix::StatStruct file_stat;
        result = posix::Stat (path.c_str (), &file_stat) == 0 &&
	posix::IsDir (file_stat);
        return result;
    }
    bool FilePath::IsRootDirectory () const
    {
      return pathname_.length () == 1
	&& IsPathSeparator (pathname_.c_str ()[0]);
    }
    bool FilePath::IsAbsolutePath () const
    {
      const char *const name = pathname_.c_str ();
        return IsPathSeparator (name[0]);
    }
    FilePath FilePath::GenerateUniqueFileName (const FilePath & directory,
					       const FilePath & base_name,
					       const char *extension)
    {
      FilePath full_pathname;
      int number = 0;
      do
	{
	  full_pathname.Set (MakeFileName
			     (directory, base_name, number++, extension));
	}
      while (full_pathname.FileOrDirectoryExists ());
      return full_pathname;
    }
    bool FilePath::IsDirectory () const
    {
      return !pathname_.empty () &&
	IsPathSeparator (pathname_.c_str ()[pathname_.length () - 1]);
    }
    bool FilePath::CreateDirectoriesRecursively () const
    {
      if (!this->IsDirectory ())
	{
	  return false;
	}
      if (pathname_.length () == 0 || this->DirectoryExists ())
	{
	  return true;
	}
      const FilePath parent (this->RemoveTrailingPathSeparator ().
			     RemoveFileName ());
      return parent.CreateDirectoriesRecursively () && this->CreateFolder ();
    }
    bool FilePath::CreateFolder () const
    {
      int result = mkdir (pathname_.c_str (), 0777);
      if (result == -1)
	{
	  return this->DirectoryExists ();
	}
      return true;
    }
    FilePath FilePath::RemoveTrailingPathSeparator () const
    {
      return IsDirectory ()
	? FilePath (String (pathname_.c_str (), pathname_.length () - 1))
	: *this;
    }
    void FilePath::Normalize ()
    {
      if (pathname_.c_str () == __null)
	{
	  pathname_ = "";
	  return;
	}
      const char *src = pathname_.c_str ();
      char *const dest = new char[pathname_.length () + 1];
      char *dest_ptr = dest;
      memset (dest_ptr, 0, pathname_.length () + 1);
      while (*src != '\0')
	{
	  *dest_ptr = *src;
	  if (!IsPathSeparator (*src))
	    {
	      src++;
	    }
	  else
	    {
	      while (IsPathSeparator (*src))
		src++;
	    }
	  dest_ptr++;
	}
      *dest_ptr = '\0';
      pathname_ = dest;
      delete[]dest;
    }
  }
}

namespace testing
{
  namespace internal
  {
    const int kStdOutFileno = 1;
    const int kStdErrFileno = 2;
    size_t GetThreadCount ()
    {
      return 0;
    }
    RE::~RE ()
    {
      if (is_valid_)
	{
	  regfree (&partial_regex_);
	  regfree (&full_regex_);
	}
      free (const_cast < char *>(pattern_));
    }
    bool RE::FullMatch (const char *str, const RE & re)
    {
      if (!re.is_valid_)
	return false;
      regmatch_t match;
      return regexec (&re.full_regex_, str, 1, &match, 0) == 0;
    }
    bool RE::PartialMatch (const char *str, const RE & re)
    {
      if (!re.is_valid_)
	return false;
      regmatch_t match;
      return regexec (&re.partial_regex_, str, 1, &match, 0) == 0;
    }
    void RE::Init (const char *regex)
    {
      pattern_ = posix::StrDup (regex);
      const size_t full_regex_len = strlen (regex) + 10;
      char *const full_pattern = new char[full_regex_len];
      snprintf (full_pattern, full_regex_len, "^(%s)$", regex);
      is_valid_ = regcomp (&full_regex_, full_pattern, 1) == 0;
      if (is_valid_)
	{
	  const char *const partial_regex = (*regex == '\0') ? "()" : regex;
	  is_valid_ = regcomp (&partial_regex_, partial_regex, 1) == 0;
	}
      switch (0)
	case 0:
	default:
	if (const::testing::AssertionResult gtest_ar_ =::testing::
	    AssertionResult (is_valid_));
	else
	  ::testing::internal::AssertHelper (::testing::TestPartResult::
					     kNonFatalFailure,
					     "gtest-port.cc",
					     167,::testing::internal::
					     GetBoolAssertionFailureMessage
					     (gtest_ar_, "is_valid_", "false",
					      "true").
					     c_str ()) =::testing::
	    Message () << "Regular expression \"" << regex <<
	    "\" is not a valid POSIX Extended regular expression.";
      delete[]full_pattern;
    }
    const char kUnknownFile[] = "unknown file";
    ::std::string FormatFileLocation (const char *file, int line)
    {
      const char *const file_name = file == __null ? kUnknownFile : file;
      if (line < 0)
	{
	  return String::Format ("%s:", file_name).c_str ();
	}
      return String::Format ("%s:%d:", file_name, line).c_str ();
    }
    ::std::string FormatCompilerIndependentFileLocation (const char *file,
							 int line)
    {
      const char *const file_name = file == __null ? kUnknownFile : file;
      if (line < 0)
	return file_name;
      else
	return String::Format ("%s:%d", file_name, line).c_str ();
    }
  GTestLog::GTestLog (GTestLogSeverity severity, const char *file, int line):severity_
      (severity)
    {
      const char *const marker =
	severity == GTEST_INFO ? "[  INFO ]" :
	severity == GTEST_WARNING ? "[WARNING]" :
	severity == GTEST_ERROR ? "[ ERROR ]" : "[ FATAL ]";
      GetStream () <<::std::endl << marker << " "
	<< FormatFileLocation (file, line).c_str () << ": ";
    }
    GTestLog::~GTestLog ()
    {
      GetStream () <<::std::endl;
      if (severity_ == GTEST_FATAL)
	{
	  fflush (stderr);
	  posix::Abort ();
	}
    }
    class CapturedStream
    {
    public:
      CapturedStream (int fd):fd_ (fd), uncaptured_fd_ (dup (fd))
      {
	char name_template[] = "/tmp/captured_stream.XXXXXX";
	const int captured_fd = mkstemp (name_template);
	  filename_ = name_template;
	  fflush (__null);
	  dup2 (captured_fd, fd_);
	  close (captured_fd);
      }
       ~CapturedStream ()
      {
	remove (filename_.c_str ());
      }
      String GetCapturedString ()
      {
	if (uncaptured_fd_ != -1)
	  {
	    fflush (__null);
	    dup2 (uncaptured_fd_, fd_);
	    close (uncaptured_fd_);
	    uncaptured_fd_ = -1;
	  }
	FILE *const file = posix::FOpen (filename_.c_str (), "r");
	const String content = ReadEntireFile (file);
	posix::FClose (file);
	return content;
      }
    private:
      static String ReadEntireFile (FILE * file);
      static size_t GetFileSize (FILE * file);
      const int fd_;
      int uncaptured_fd_;
      ::std::string filename_;
      CapturedStream (CapturedStream const &);
      void operator= (CapturedStream const &);
    };
    size_t CapturedStream::GetFileSize (FILE * file)
    {
      fseek (file, 0, 2);
      return static_cast < size_t > (ftell (file));
    }
    String CapturedStream::ReadEntireFile (FILE * file)
    {
      const size_t file_size = GetFileSize (file);
      char *const buffer = new char[file_size];
      size_t bytes_last_read = 0;
      size_t bytes_read = 0;
      fseek (file, 0, 0);
      do
	{
	  bytes_last_read =
	    fread (buffer + bytes_read, 1, file_size - bytes_read, file);
	  bytes_read += bytes_last_read;
	}
      while (bytes_last_read > 0 && bytes_read < file_size);
      const String content (buffer, bytes_read);
      delete[]buffer;
      return content;
    }
    static CapturedStream *g_captured_stderr = __null;
    static CapturedStream *g_captured_stdout = __null;
    void CaptureStream (int fd, const char *stream_name,
			CapturedStream ** stream)
    {
      if (*stream != __null)
	{
	  ::testing::internal::GTestLog (::testing::internal::GTEST_FATAL,
					 "gtest-port.cc",
					 611).GetStream () << "Only one " <<
	    stream_name << " capturer can exist at a time.";
	}
      *stream = new CapturedStream (fd);
    }
    String GetCapturedStream (CapturedStream ** captured_stream)
    {
      const String content = (*captured_stream)->GetCapturedString ();
      delete *captured_stream;
      *captured_stream = __null;
      return content;
    }
    void CaptureStdout ()
    {
      CaptureStream (kStdOutFileno, "stdout", &g_captured_stdout);
    }
    void CaptureStderr ()
    {
      CaptureStream (kStdErrFileno, "stderr", &g_captured_stderr);
    }
    String GetCapturedStdout ()
    {
      return GetCapturedStream (&g_captured_stdout);
    }
    String GetCapturedStderr ()
    {
      return GetCapturedStream (&g_captured_stderr);
    }
    ::std::vector < String > g_argvs;
    const::std::vector < String > &GetArgvs ()
    {
      return g_argvs;
    }
    static String FlagToEnvVar (const char *flag)
    {
      const String full_flag = (Message () << "gtest_" << flag).GetString ();
      Message env_var;
      for (size_t i = 0; i != full_flag.length (); i++)
	{
	  env_var << ToUpper (full_flag.c_str ()[i]);
	}
      return env_var.GetString ();
    }
    bool ParseInt32 (const Message & src_text, const char *str, Int32 * value)
    {
      char *end = __null;
      const long long_value = strtol (str, &end, 10);
      if (*end != '\0')
	{
	  Message msg;
	  msg << "WARNING: " << src_text
	    << " is expected to be a 32-bit integer, but actually"
	    << " has value \"" << str << "\".\n";
	  printf ("%s", msg.GetString ().c_str ());
	  fflush (stdout);
	  return false;
	}
      const Int32 result = static_cast < Int32 > (long_value);
      if (long_value == 9223372036854775807L
	  || long_value == (-9223372036854775807L - 1L)
	  || result != long_value)
	{
	  Message msg;
	  msg << "WARNING: " << src_text
	    << " is expected to be a 32-bit integer, but actually"
	    << " has value " << str << ", which overflows.\n";
	  printf ("%s", msg.GetString ().c_str ());
	  fflush (stdout);
	  return false;
	}
      *value = result;
      return true;
    }
    bool BoolFromGTestEnv (const char *flag, bool default_value)
    {
      const String env_var = FlagToEnvVar (flag);
      const char *const string_value = posix::GetEnv (env_var.c_str ());
      return string_value == __null ?
	default_value : strcmp (string_value, "0") != 0;
    }
    Int32 Int32FromGTestEnv (const char *flag, Int32 default_value)
    {
      const String env_var = FlagToEnvVar (flag);
      const char *const string_value = posix::GetEnv (env_var.c_str ());
      if (string_value == __null)
	{
	  return default_value;
	}
      Int32 result = default_value;
      if (!ParseInt32 (Message () << "Environment variable " << env_var,
		       string_value, &result))
	{
	  printf ("The default value %s is used.\n",
		  (Message () << default_value).GetString ().c_str ());
	  fflush (stdout);
	  return default_value;
	}
      return result;
    }
    const char *StringFromGTestEnv (const char *flag,
				    const char *default_value)
    {
      const String env_var = FlagToEnvVar (flag);
      const char *const value = posix::GetEnv (env_var.c_str ());
      return value == __null ? default_value : value;
    }
  }
}

namespace testing
{
  namespace
  {
    using::std::ostream;
    void PrintByteSegmentInObjectTo (const unsigned char *obj_bytes,
				     size_t start, size_t count, ostream * os)
    {
      char text[5] = "";
      for (size_t i = 0; i != count; i++)
	{
	  const size_t j = start + i;
	  if (i != 0)
	    {
	      if ((j % 2) == 0)
		*os << ' ';
	      else
		*os << '-';
	    }
	  snprintf (text, sizeof (text), "%02X", obj_bytes[j]);
	  *os << text;
	}
    }
    void PrintBytesInObjectToImpl (const unsigned char *obj_bytes,
				   size_t count, ostream * os)
    {
      *os << count << "-byte object <";
      const size_t kThreshold = 132;
      const size_t kChunkSize = 64;
      if (count < kThreshold)
	{
	  PrintByteSegmentInObjectTo (obj_bytes, 0, count, os);
	}
      else
	{
	  PrintByteSegmentInObjectTo (obj_bytes, 0, kChunkSize, os);
	  *os << " ... ";
	  const size_t resume_pos = (count - kChunkSize + 1) / 2 * 2;
	  PrintByteSegmentInObjectTo (obj_bytes, resume_pos,
				      count - resume_pos, os);
	}
      *os << ">";
    }
  }
  namespace internal2
  {
    void PrintBytesInObjectTo (const unsigned char *obj_bytes, size_t count,
			       ostream * os)
    {
      PrintBytesInObjectToImpl (obj_bytes, count, os);
    }
  }
  namespace internal
  {
    enum CharFormat
    {
      kAsIs,
      kHexEscape,
      kSpecialEscape
    };
    inline bool IsPrintableAscii (wchar_t c)
    {
      return 0x20 <= c && c <= 0x7E;
    }
    template < typename UnsignedChar, typename Char >
      static CharFormat PrintAsCharLiteralTo (Char c, ostream * os)
    {
      switch (static_cast < wchar_t > (c))
	{
	case L'\0':
	  *os << "\\0";
	  break;
	case L'\'':
	  *os << "\\'";
	  break;
	case L'\\':
	  *os << "\\\\";
	  break;
	case L'\a':
	  *os << "\\a";
	  break;
	case L'\b':
	  *os << "\\b";
	  break;
	case L'\f':
	  *os << "\\f";
	  break;
	case L'\n':
	  *os << "\\n";
	  break;
	case L'\r':
	  *os << "\\r";
	  break;
	case L'\t':
	  *os << "\\t";
	  break;
	case L'\v':
	  *os << "\\v";
	  break;
	default:
	  if (IsPrintableAscii (c))
	    {
	      *os << static_cast < char >(c);
	      return kAsIs;
	    }
	  else
	    {
	      *os << String::Format ("\\x%X",
				     static_cast < UnsignedChar > (c));
	      return kHexEscape;
	    }
	}
      return kSpecialEscape;
    }
    static CharFormat PrintAsWideStringLiteralTo (wchar_t c, ostream * os)
    {
      switch (c)
	{
	case L'\'':
	  *os << "'";
	  return kAsIs;
	case L'"':
	  *os << "\\\"";
	  return kSpecialEscape;
	default:
	  return PrintAsCharLiteralTo < wchar_t > (c, os);
	}
    }
    static CharFormat PrintAsNarrowStringLiteralTo (char c, ostream * os)
    {
      return PrintAsWideStringLiteralTo (static_cast < unsigned char >(c),
					 os);
    }
    template < typename UnsignedChar, typename Char >
      void PrintCharAndCodeTo (Char c, ostream * os)
    {
      *os << ((sizeof (c) > 1) ? "L'" : "'");
      const CharFormat format = PrintAsCharLiteralTo < UnsignedChar > (c, os);
      *os << "'";
      if (c == 0)
	return;
      *os << " (" << String::Format ("%d", c).c_str ();
      if (format == kHexEscape || (1 <= c && c <= 9))
	{
	}
      else
	{
	  *os << String::Format (", 0x%X",
				 static_cast < UnsignedChar > (c)).c_str ();
	}
      *os << ")";
    }
    void PrintTo (unsigned char c,::std::ostream * os)
    {
      PrintCharAndCodeTo < unsigned char >(c, os);
    }
    void PrintTo (signed char c,::std::ostream * os)
    {
      PrintCharAndCodeTo < unsigned char >(c, os);
    }
    void PrintTo (wchar_t wc, ostream * os)
    {
      PrintCharAndCodeTo < wchar_t > (wc, os);
    }
    static void PrintCharsAsStringTo (const char *begin, size_t len,
				      ostream * os)
    {
      *os << "\"";
      bool is_previous_hex = false;
      for (size_t index = 0; index < len; ++index)
	{
	  const char cur = begin[index];
	  if (is_previous_hex && IsXDigit (cur))
	    {
	      *os << "\" \"";
	    }
	  is_previous_hex =
	    PrintAsNarrowStringLiteralTo (cur, os) == kHexEscape;
	}
      *os << "\"";
    }
    void UniversalPrintArray (const char *begin, size_t len, ostream * os)
    {
      PrintCharsAsStringTo (begin, len, os);
    }
    static void PrintWideCharsAsStringTo (const wchar_t * begin, size_t len,
					  ostream * os)
    {
      *os << "L\"";
      bool is_previous_hex = false;
      for (size_t index = 0; index < len; ++index)
	{
	  const wchar_t cur = begin[index];
	  if (is_previous_hex && isascii (cur)
	      && IsXDigit (static_cast < char >(cur)))
	    {
	      *os << "\" L\"";
	    }
	  is_previous_hex =
	    PrintAsWideStringLiteralTo (cur, os) == kHexEscape;
	}
      *os << "\"";
    }
    void PrintTo (const char *s, ostream * os)
    {
      if (s == __null)
	{
	  *os << "NULL";
	}
      else
	{
	  *os << ImplicitCast_ < const void *>(s) << " pointing to ";
	  PrintCharsAsStringTo (s, strlen (s), os);
	}
    }
    void PrintTo (const wchar_t * s, ostream * os)
    {
      if (s == __null)
	{
	  *os << "NULL";
	}
      else
	{
	  *os << ImplicitCast_ < const void *>(s) << " pointing to ";
	  PrintWideCharsAsStringTo (s, wcslen (s), os);
	}
    }
    void PrintStringTo (const::std::string & s, ostream * os)
    {
      PrintCharsAsStringTo (s.data (), s.size (), os);
    }
    void PrintWideStringTo (const::std::wstring & s, ostream * os)
    {
      PrintWideCharsAsStringTo (s.data (), s.size (), os);
    }
  }
}

namespace testing
{
  using internal::GetUnitTestImpl;
    internal::String TestPartResult::ExtractSummary (const char *message)
  {
    const char *const stack_trace =
      strstr (message, internal::kStackTraceMarker);
      return stack_trace ==
      __null ? internal::String (message) : internal::String (message,
							      stack_trace -
							      message);
  }
  std::ostream & operator<< (std::ostream & os, const TestPartResult & result)
  {
    return os
      << result.file_name () << ":" << result.line_number () << ": "
      << (result.type () == TestPartResult::kSuccess ? "Success" :
	  result.type () == TestPartResult::kFatalFailure ? "Fatal failure" :
	  "Non-fatal failure") << ":\n" << result.message () << std::endl;
  }
  void TestPartResultArray::Append (const TestPartResult & result)
  {
    array_.push_back (result);
  }
  const TestPartResult & TestPartResultArray::GetTestPartResult (int index) const
  {
    if (index < 0 || index >= size ())
      {
	printf ("\nInvalid index (%d) into TestPartResultArray.\n", index);
	internal::posix::Abort ();
      }
    return array_[index];
  }
  int TestPartResultArray::size () const
  {
    return static_cast < int >(array_.size ());
  }
  namespace internal
  {
    HasNewFatalFailureHelper::HasNewFatalFailureHelper
      ():has_new_fatal_failure_ (false),
      original_reporter_ (GetUnitTestImpl
			  ()->GetTestPartResultReporterForCurrentThread ())
    {
      GetUnitTestImpl ()->SetTestPartResultReporterForCurrentThread (this);
    }
    HasNewFatalFailureHelper::~HasNewFatalFailureHelper ()
    {
      GetUnitTestImpl ()->SetTestPartResultReporterForCurrentThread
	(original_reporter_);
    }
    void HasNewFatalFailureHelper::ReportTestPartResult (const TestPartResult
							 & result)
    {
      if (result.fatally_failed ())
	has_new_fatal_failure_ = true;
      original_reporter_->ReportTestPartResult (result);
    }
  }
}

namespace testing
{
  namespace internal
  {
    static const char *SkipSpaces (const char *str)
    {
      while (IsSpace (*str))
	str++;
      return str;
    }
    const char *TypedTestCasePState::VerifyRegisteredTestNames (const char
								*file,
								int line,
								const char
								*registered_tests)
    {
      typedef::std::set < const char *>::const_iterator DefinedTestIter;
        registered_ = true;
        registered_tests = SkipSpaces (registered_tests);
      Message errors;
      ::std::set < String > tests;
      for (const char *names = registered_tests; names != __null;
	   names = SkipComma (names))
	{
	  const String name = GetPrefixUntilComma (names);
	  if (tests.count (name) != 0)
	    {
	      errors << "Test " << name << " is listed more than once.\n";
	      continue;
	    }
	  bool found = false;
	  for (DefinedTestIter it = defined_test_names_.begin ();
	       it != defined_test_names_.end (); ++it)
	    {
	      if (name == *it)
		{
		  found = true;
		  break;
		}
	    }
	  if (found)
	    {
	      tests.insert (name);
	    }
	  else
	    {
	      errors << "No test named " << name
		<< " can be found in this test case.\n";
	    }
	}
      for (DefinedTestIter it = defined_test_names_.begin ();
	   it != defined_test_names_.end (); ++it)
	{
	  if (tests.count (*it) == 0)
	    {
	      errors << "You forgot to list test " << *it << ".\n";
	    }
	}
      const String & errors_str = errors.GetString ();
      if (errors_str != "")
	{
	  fprintf (stderr, "%s %s", FormatFileLocation (file, line).c_str (),
		   errors_str.c_str ());
	  fflush (stderr);
	  posix::Abort ();
	}
      return registered_tests;
    }
  }
}

int main(int argc, char **argv) {
	std::cout << "Running main() from gtest_main.cc\n";
	testing::InitGoogleTest(&argc, argv);
	return (::testing::UnitTest::GetInstance()->Run());
}
