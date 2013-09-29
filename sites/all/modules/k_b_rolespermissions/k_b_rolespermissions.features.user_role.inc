<?php
/**
 * @file
 * k_b_rolespermissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function k_b_rolespermissions_user_default_roles() {
  $roles = array();

  // Exported role: Branch Manager.
  $roles['Branch Manager'] = array(
    'name' => 'Branch Manager',
    'weight' => 3,
  );

  // Exported role: Customer.
  $roles['Customer'] = array(
    'name' => 'Customer',
    'weight' => 4,
  );

  return $roles;
}
