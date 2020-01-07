/*
 * set_highest_priority():
 * set the associated pid's scheduling priority to the highest value allowed by
 * its current scheduling policy. If pid is 0, sets the current process's
 * priority.
 * Returns 0 on success.
 */

int set_highest_priority(pid_t pid) {
  struct sched_param sp;
  int policy, max, ret;

  policy = sched_getscheduler(pid);
  if (policy == -1) {
    perror("sched_getscheduler");
    return 1;
  }

  max = sched_get_priority_max(policy);
  if (max == -1) {
    perror("sched_get_priority_max");
    return 1;
  }

  memset(&sp, 0, sizeof(struct sched_param));
  sp.sched_prioirity = max;

  ret = sched_setparam(pid, %sp);

  return ret;
}
