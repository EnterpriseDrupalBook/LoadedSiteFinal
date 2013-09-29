<?php
/**
 * @file
 * k_b_rules_and_services.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function k_b_rules_and_services_default_rules_configuration() {
  $items = array();
  $items['rules_update_all_menu_item_prices'] = entity_import('rules_config', '{ "rules_update_all_menu_item_prices" : {
      "LABEL" : "Update All Menu Item Prices",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "views_rules", "rules" ],
      "USES VARIABLES" : { "price_multiplier" : { "label" : "Price Multiplier", "type" : "decimal" } },
      "DO" : [
        { "VIEW LOOP" : {
            "VIEW" : "all_menu_items",
            "DISPLAY" : "views_rules_1",
            "ROW VARIABLES" : {
              "title" : { "item_title" : "Content: Title" },
              "nid" : { "item_nid" : "Nid" },
              "price" : { "item_price" : "Price" }
            },
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "item-price" ],
                    "op" : "*",
                    "input_2" : [ "price-multiplier" ]
                  },
                  "PROVIDE" : { "result" : { "new_price" : "New Price" } }
                }
              },
              { "entity_fetch" : {
                  "USING" : { "type" : "node", "id" : [ "item-nid" ] },
                  "PROVIDE" : { "entity_fetched" : { "fetched_menu_item" : "Fetched Menu Item" } }
                }
              },
              { "component_rules_update_menu_item_price" : { "menu_item" : [ "fetched-menu-item" ], "new_price" : [ "new-price" ] } },
              { "entity_save" : { "data" : [ "fetched-menu-item" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_update_menu_item_price'] = entity_import('rules_config', '{ "rules_update_menu_item_price" : {
      "LABEL" : "Update Menu Item Price",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "menu_item" : { "label" : "Menu Item", "type" : "node" },
        "new_price" : { "label" : "New Price", "type" : "decimal" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "menu-item" ], "field" : "field_price" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "menu-item:field-price" ], "value" : [ "new-price" ] } }
      ]
    }
  }');
  return $items;
}
