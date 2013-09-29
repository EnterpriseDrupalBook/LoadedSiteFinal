<?php
/**
 * @file
 * k_b_rules_and_services.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function k_b_rules_and_services_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function k_b_rules_and_services_views_api() {
  return array("api" => "3.0");
}
